#include "polygon.hpp"
#include <iostream>
#include <cmath>

class octagon : public polygon {
public:
    virtual double area() const {
        // 2 (1+^2) a2
        return 2 * ( 1 + sqrt(2)) * (side_length_ * side_length_);
    }
};


// the class factories

extern "C" polygon* create() {
    std::cout << "Creating octagon" << std::endl;
    return new octagon;
}

extern "C" void destroy(polygon* p) {
    std::cout << "Destroying octagon" << std::endl;
    delete p;
}