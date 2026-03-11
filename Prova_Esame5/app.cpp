#include "BBH.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TRandom.h"

int main(void) {
    int N = 1e4; //Number of extractions
    std::vector<double> AngMom; //Angular momenta extracted randomly on a sphere
    AngMom.resize(3);
    BBH tempBBH; //Binary BlackHole system used as a temporary variable
    std::vector<BBH> Systems; //Vector full of BBH with random values
    TRandom randomSample; //needed to use the sphere function
    randomSample.SetSeed(time(NULL));
    TH1F h1("h1", "Chirp Mass distribution", 100, 5.0, 100.0);//histogram class
    h1.GetXaxis()->SetTitle("ChirpMass");
    h1.GetYaxis()->SetTitle("Occurrencies");

    for(int i=0; i<N; i++) { //I initialize the firs 10^4 Binary Systems with just masses
        tempBBH.setM1(randomSample.Uniform(5, 100));
        tempBBH.setM2(randomSample.Uniform(5, 100));
        Systems.push_back(tempBBH);
        h1.Fill(Systems[i].ChirpMass());
    }
    //plot the first data 
    TCanvas c1("c1","ChirpMass Plot",1024,800);
    h1.Draw();
    c1.SaveAs("ChirpMass.png");

    //Do the second generation of data
    TH1F h2("h2", "Effective spin distribution", 100, -1, 1);//histogram class
    h2.GetXaxis()->SetTitle("Effective Spin");
    h2.GetYaxis()->SetTitle("Occurrencies");
    
    for(std::vector<BBH>::iterator it = Systems.begin(); it != Systems.end(); it++) { //I add to the past masses also the angular momenta
        randomSample.Sphere(AngMom[0], AngMom[1], AngMom[2], 1);
        it->setChi1(AngMom);
        randomSample.Sphere(AngMom[0], AngMom[1], AngMom[2], 1);
        it->setChi2(AngMom);
        h2.Fill(it->ChiEff());
    }
    //Plot
    h2.Draw();
    c1.SaveAs("EffectiveSpin.png");
    return 0;
}