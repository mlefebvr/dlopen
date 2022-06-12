#include "polygon.hpp"
#include <iostream>
#include <cmath>

class triangle : public polygon {
public:
    virtual double area() const {
        return side_length_ * side_length_ * sqrt(3) / 2;
    }
};


// the class factories

extern "C" polygon* create() {
    std::cout << "Creating triangle" << std::endl;
    return new triangle;
}

extern "C" void destroy(polygon* p) {
    std::cout << "Destroying triangle" << std::endl;
    delete p;
}