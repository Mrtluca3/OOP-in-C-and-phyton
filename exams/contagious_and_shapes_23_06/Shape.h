#ifndef Shape_h
#define Shape_h
#include <iostream>
class Shape {
    private:
    std::string label_;

    public:
    //ctor
    Shape(const std::string& label): label_(label) {}
    //dtor
    ~Shape() = default;

    //getter
    std::string Label(){return label_;}
    //print
    virtual void print() = 0; //abstract method

};

#endif