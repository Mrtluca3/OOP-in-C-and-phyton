
#ifndef Planet_h
#define Planet_h

class Planet {
    public:
    Planet(); //constructor
    Planet(double R, double M); //constructor
    Planet(Planet& P); //copy constructor
    ~Planet(); //destructor
    
    //Getters
    double getMass() const;
    double getRadius() const;

    //Setters 
    void setMass(const double& M);
    void setRadius(const double& R);

    private:
    double M_, R_; //Mass and radius of the planet

};

#endif