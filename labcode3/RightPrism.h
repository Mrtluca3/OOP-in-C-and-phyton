#include "Shape.h"

#ifndef RightPrism_h
#define RightPrism_h
class RightPrism: public Shape {
    public: 
        RightPrism(const double& h=1., Shape* base=nullptr, const std::string& name="RightPrism");
        virtual void print();
        


        //This 2 not needed
        // virtual double Perimeter()=0; already inherited as abstract
        // virtual double Surface()=0;

        virtual double Volume() {return base_->Dimension()[1] * h_; }

        Shape* base(){return base_;}
        double h(){return h_;}
        virtual ~RightPrism() {
            std::cout<< "Dtor RightPrism: " << name() << std::endl; 
        }

        void resetbase(){base_=nullptr;}
        private:
        double h_;
        Shape* base_;

};
#endif 