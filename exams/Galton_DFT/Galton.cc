#include "Galton.h"


Galton::Galton(int Nrows, double prob_dx): board_(int(0.5*Nrows*(Nrows+1)), 0), N_(Nrows), prob_(prob_dx) { //Nrows
    std::random_device rd; //seeding
    gen_.seed(rd()); 
    dist_ = std::uniform_real_distribution<>(0.0, 1.0);
    N_exp_=0;
    }

Galton& Galton::Singlebead(){
    double p;
    int pos;
    pos=0;
    N_exp_+=1;
    board_[0]+=1;
    for(size_t i=1; i<N_; i++){
        p=dist_(gen_);
        if(p < prob_) {
            pos+=1;
            
        }
        // std::cout << pos << " tot: ";
        //else remains pos
        // std::cout<<pos+int(0.5*i*(i+1))<<std::endl;
        board_[pos+int(0.5*i*(i+1))] +=1;
    }
    return *this;
}

Galton& Galton::Simulation(int Nexp){
    for(int j=0; j<Nexp; j++)
        Singlebead();
    return *this;
}

Galton& Galton::Reset(){
    std::cout << "Resetting.." << std::endl; 
    board_.assign(int(0.5*N_*(N_+1)), 0);
    N_exp_=0;
    return *this;
}

Galton& Galton::Print(){
    using namespace std;
    cout << "Galton Board with " << N_ << " rows and " << N_exp_ << " beads dropped" <<endl;
    for(int i=0; i<N_; i++){
        for(int j=i; j<(N_-1); j++)
            cout << " ";

        for(int j=0; j<(i+1); j++)
            {
                // cout << int(0.5*i*(i+1))+j << ": ";
                cout << board_[int(0.5*i*(i+1))+j] <<" ";
            }
        for(int j=i; j<(N_-1); j++)
            cout << " ";

        cout << endl;
    }
    return *this;
}
