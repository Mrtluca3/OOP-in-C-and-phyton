#ifndef Atmosphere_h
#define Atmosphere_h
class Atmosphere{
    public:
        //ctor
        Atmosphere(const double& F107=182.5, const double& Ap=200, const double& Cd=2.);
        //getters
        inline const double F() const {return F_;}
        inline const double Ap() const {return Ap_;}
        inline double Cd() const {return Cd_;}
        //dtor
        ~Atmosphere() =default;

        //specific methods to compute density
        double rho(const double& h) const;
        //molecular mass of air and temperature as funzion of solar radio flux
        const double Mu(const double& h)const {return 27-0.012*(h-200);}
        const double Temperature() const {return 900+2.5*(F_-70)+1.5*Ap_;}
    private:
        double F_;
        double Ap_;
        double Cd_;
};

#endif