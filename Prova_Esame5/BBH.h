#include <iostream>
#include <vector>

class BBH {
    public:
    BBH(); //default constructor, assumes m1=m2 and in units of solar masses.
    BBH(const BBH& B); //copy constructor
    BBH(double m1, double m2, const std::vector<double>& chi1, const std::vector<double>& chi2); //constructor - Notice m1,m2 are in unit of solar masses.
    ~BBH(); //destructor

    //methods
    double ChiEff(); //Changes chieff of the class
    double ChirpMass(); //Changes the chirpmass of the class

    //getters
    double getM1() const;
    double getM2() const;
    std::vector<double> getChi1() const;
    std::vector<double> getChi2() const;

    //setters
    void setM1(const double& M1);
    void setM2(const double& M2);
    void setChi1(const std::vector<double>& Chi1);
    void setChi2(const std::vector<double>& Chi2);

    void Print(); //Prints all the informations about the binary system, can't be const since it calls non const methods

    private:
    double m1_, m2_, Mc_, ChiE_; //the last two are chirp mass and chi effective respectively
    std::vector<double> chi1_, chi2_;
};