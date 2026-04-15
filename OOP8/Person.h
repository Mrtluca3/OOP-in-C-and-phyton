#ifndef Person_h
#define Person_h

#include <string>

class Person {
  public:
    Person(const std::string& name);
    ~Person();
    std::string name() const {  return name_; }
    virtual void print() const;
    // void print() const; //what happens if I remove virtual only to a base class? creates compiler error

  private:
    std::string name_;
};
#endif
