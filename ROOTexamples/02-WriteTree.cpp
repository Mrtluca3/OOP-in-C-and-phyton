// standard library header files
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

// ROOT header files
#include "TRandom3.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TStyle.h" // needed to change display options for stats and fit paramters

// My header files
#include "Datum.h"

// For the time being we will not use command line variables,
// but we get everything ready to do so with argc and argv[].
int main(int argc, char* argv[]) {

  // With a random generator, we want to generate
  // 1) the TRUE VALUE of the observable in a given range and then
  // 2) the VALUE MEASURED by the detector, taking into account its resolution
  // The range [x1,x2] for step 1
  double x1=0.9, x2=1.1;
  // For step 2 we condider a gaussian resolution of 20%
  double resol = 0.20;

  // Get ready to create histograms containing the TRUE and MEASURED samples
  // The histogram limits are set as a function of interval and resolution
  double xlo = x1*(1-5*resol);
  double xhi = x2*(1+5*resol);
  int nbins = 100;
  double binwidth = (xhi-xlo) / nbins;
  std::cout << "# bins: " << nbins << "\t bin width: " << binwidth << std::endl;
  // The three histogram instances (name, title, number of bins, range)
  TH1F hx1("hx1", "distribution of measured x", nbins, xlo, xhi);
  TH1F hdx1("hdx1", "distribution of x uncertainty", nbins, -5*resol , 5*resol);
  TH1F hpull("hpull", "pull distribution", nbins, -6 , 6);

  // Start up a new random generator...
  TRandom3*  gen = new TRandom3();
  // ...exploiting the machine clock for the seed
  gen->SetSeed(0);

  // Number of measurements
  int nmeas = 1000;
  std::vector<Datum> data;

  // Loop over the measurements
  for(int i=0; i<nmeas; ++i) {

    // Genarate a TRUE value: sample from a flat distribution in [x1, x2]
    double x0 = x1 + gen->Uniform(x2-x1);

    // Generate the MEASURED value based on the true value and resolution
    double x = gen->Gaus(x0, x0*resol);

    // Generate the UNCERTAINTY value based on the resolution and the measured value
    double dx = x*resol;

    // Store Datum in vector
    data.push_back(Datum(x, dx));

    // Fill histograms: measured value, uncertainty, relative uncertainty
    hx1.Fill(x);
    hdx1.Fill(dx);
    hpull.Fill((x-x0)/dx);
  }

  // After generating the data, we take care of plotting the results
  TCanvas canv("canv", "canvas for plotting", 1280, 1024);

  // Show all statistical and fit parameters with the following 2 lines:
  // https://root.cern.ch/doc/master/classTPaveStats.html
  gStyle->SetOptStat(111111);
  gStyle->SetOptFit(1111);

  // Provide an x-axis label and store to pdf
  hx1.GetXaxis()->SetTitle("Distribution of x [GeV]");
  hx1.Draw();
  canv.SaveAs("~/OOP_physics/execute/x.pdf");

  hdx1.GetXaxis()->SetTitle("Distribution of uncertainty \\deltax [GeV]");
  hdx1.Draw("pe");
  canv.SaveAs("~/OOP_physics/execute/dx.pdf");

  // Create and store a figure with with three panels:
  // the canvas contains 2x2 panels and the first 3 are used.
  canv.Clear();
  canv.Divide(2,2);
  canv.cd(1);
  hx1.Fit("gaus");
  hx1.Draw();
  canv.cd(2);
  hdx1.Fit("gaus");
  hdx1.Draw("pe");
  canv.cd(3);
  hpull.GetXaxis()->SetTitle("Distribution of (x-x0)/\\deltax");
  hpull.Fit("gaus");
  hpull.Draw();
  canv.SaveAs("~/OOP_physics/execute/plotsmultiple.pdf");

  // Store output to file
  std::ofstream ofile; //output file stream: use to create a dataframe tabular
  std::string ofname("~/OOP_physics/execute/data.txt");
  std::cout << "storing data in " << ofname << std::endl;
  ofile.open( ofname );

  for(std::vector<Datum>::const_iterator it = data.begin(); it != data.end(); ++it) {
    ofile << std::setprecision(5) << std::fixed ;
    ofile << it->value() << "\t" << it->error() << std::endl;
  }
  ofile.close();
  std::cout << ofname << " output file successfully created" << std::endl;

  // ==== store data in a TTree
  // Open a root file
  TString rootfname("~/OOP_physics/execute/mydata2.root");
  // RECREATE: create a new file; if the file already exists it will be overwritten
  TFile* orootfile = new TFile( rootfname, "RECREATE");
  if( !orootfile->IsOpen() ) {
    std::cout << "problems creating root file: exiting... " << std::endl;
    exit(-1);
  }
  std::cout << "storing output in root file " << rootfname << std::endl;

  // Create a new TTree object
  TTree* tree = new TTree("mydatatree", "tree containing our data");
  // The name of the TTree object (mydatatree), and not the name of the C++
  // variable (tree), is important because ROOT stores all objects in a
  // TFile with their names
  
  // Variables to be stored in the tree (branches): values and errors
  double x, dx;
  // Set the info for each branch of the tree to correspond to our data:
  // * we set the reference to x and dx in the two branches value and error of the tree
  // A Branch function has 3 arguments:
  // 1) the branch name
  // 2) a pointer to variable in memory
  // 3) the type of the variable in the branch ("value/D" which is a double)
  // NOTE THAT "D" INDICATES THE SIZE OF A DOUBLE HERE.
  tree->Branch("valuebranch", &x,  "value/D");
  tree->Branch("errorbranch", &dx, "error/D");

  // Take care of the leaves
  // * iterate over the data to be stored
  // * assign the values to x and dx
  // * fill the tree
  for(std::vector<Datum>::const_iterator it = data.begin(); it != data.end(); ++it) {
    // Assign values to C++ variables that are going to be stored in the branch
    x = it->value();
    dx = it->error();
    /////////////////////////////////////////STORE IN THE TREE//////////////////////
    // Store data in tree IN MEMORY on the basis of the tree->Branch(...) calls
    tree->Fill();
  }

  // Actually write tree in file on disk
  tree->Write();

  // Print some info about the tree
  std::cout << "Print some info about the tree with tree->Print()"<< std::endl;
  tree->Print();

  // ==== Done using the TTree
  delete tree;

  // Critical to close the file we had opened!
  orootfile->Close();

  // ==== Done storing data and using the generator
  delete orootfile;
  delete gen;

  // Exit
  return 0;
}
