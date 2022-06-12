#include "polygon.hpp"
#include <iostream>
#include <cmath>

class cube : public polygon {
public:
    virtual double area() const {
        return side_length_ * side_length_;
    }
};


// the class factories

extern "C" polygon* create() {
    std::cout << "Creating cube" << std::endl;
    return new cube;
}

extern "C" void destroy(polygon* p) {
    std::cout << "Destroying cube" << std::endl;
    delete p;
}