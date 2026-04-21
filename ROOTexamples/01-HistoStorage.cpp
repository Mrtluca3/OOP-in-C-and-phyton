// standard library header files
#include <iostream>

// ROOT header files: random numbers, plotting, file storage
#include "TRandom3.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TFile.h"

// For the time being we will not use command line variables,
// but we get everything ready to do so with argc and argv[].
int main(int argc, char* argv[]) {

  // The string containing the name of the output file
  TString rootfname("./../execute/myoutput.root");
  // Open the output TFile and if it already exists overwite it
  TFile rfile(rootfname, "RECREATE");
  // Make sure the file was opened successfully.
  // Typical causes for failure are: 1) wrong path, 2) no write privilege
  if( !rfile.IsOpen() ) {
    std::cout << "problems creating root file: exiting... " << std::endl;
    exit(-1);
  }
  std::cout << "storing output in root file " << rootfname << std::endl;

  // With a random generator, we want to generate
  // 1) the TRUE VALUE of the observable in a given range and then
  // 2) the VALUE MEASURED by the detector, taking into account its resolution
  // The range [x1,x2] for step 1
  double x1=0.9, x2=1.1;
  // The (Gaussian) resolution for step 2 (set to 10%)
  double resol = 0.10;

  // Get ready to create histograms containing the TRUE and MEASURED samples
  // The histogram limits are set as a function of interval and resolution
  double xlo = x1*(1-5*resol);
  double xhi = x2*(1+5*resol);
  int nbins = 100;
  double binwidth = (xhi-xlo) / nbins;
  std::cout << "# bins: " << nbins << "\t bin width: " << binwidth << std::endl;
  // The two histogram instances (name, title, number of bins, range)
  TH1F hx1("hx1", "distribution of true x", nbins, xlo, xhi);
  // The 'd' is for detector
  TH1F hdx1("hdx1", "distribution of measured x", nbins, xlo , xhi);

  // Start up a new random generator... (we have a new: we will need a delete!)
  TRandom3*  gen = new TRandom3();
  // ...exploiting the machine clock for the seed
  gen->SetSeed(0);

  // Number of measurements
  int nsig = 10000;

  // Loop over the measurements
  for(int i=0; i<nsig; ++i) {

    // Genarate a TRUE value: sample from a flat distribution in [x1, x2]
    double x = x1 + gen->Uniform(x2-x1);

    // Generate the MEASURED value based on the true value and resolution
    double dx = gen->Gaus(x, x*resol);

    // Fill in histogram instances
    hx1.Fill(x);
    hdx1.Fill(dx);
  }

  // After generating the data, we take care of plotting the results:
  // * create canvas (name, title, window size in pixels)
  TCanvas canv("canv", "canvas for plotting", 1280, 1024);
  // * start from TRUE values and customize the x axis label
  hx1.GetXaxis()->SetTitle("Distribution of x [GeV]");
  // * plot
  hx1.Draw();
  // * store to file in 2 formats
  // canv.SaveAs("./x.pdf");
  canv.SaveAs("./x.jpg");
  // * move to the MEASURED values
  hdx1.GetXaxis()->SetTitle("Distribution of uncertainty \\Delta x [GeV]");
  // * in this case, show points with error bars
  hdx1.Draw("pe");
  hdx1.SetFillColor(kGreen);

  // canv.SaveAs("./dx.pdf");
  // canv.SaveAs("./dx.jpg");

  // A simple example of fitting with predefined functions
  // https://root.cern.ch/root/htmldoc/guides/users-guide/FittingHistograms.html
  // * fit histogram of MEASURED values with Gaussian function
  hdx1.Fit("gaus");
  // hdx1.Draw();
  // canv.SaveAs("./dxfit.pdf");
  canv.SaveAs("./dxfit.jpg");

  // Delete the random generator now we are done with it
  // [We had new, here is delete!]
  delete gen;

  // Store both histograms to file
  std::cout << "Saving in the file" << std::endl; 
  hx1.Write();
  hdx1.Write();

  // Critical to close the file we had opened!
  rfile.Close();

  // Exit
  return 0;
}
