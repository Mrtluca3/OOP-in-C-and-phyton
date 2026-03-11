#ifndef Atmosphere_h
#define Atmosphere_h

class Atmosphere {
    public:
    friend class FlySatellite; // Want it the onlyone to be able to change height
    Atmosphere();
    Atmosphere(const double& F_ten, const double& Ad, const double& Cd); // Constructor
    Atmosphere(const Atmosphere& A); //Copy constructor
    ~Atmosphere(); // Destructor

    //getters
    double getF_ten() const;
    double get_Ad() const;
    double get_Cd() const;
    double getTemp() const;
    double getDensity() const;
    double getViscosity() const;
    double getHeight() const;

    private: 
    void set_height(const double& h); //Updates all values related to h
    double rho_, mu_, h_, T_, F_ten_, Ad_, Cd_;

};

#endif