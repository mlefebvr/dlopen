#include "polygon.h"
#include <iostream>
#include <dlfcn.h>

int main(int argc, char **argv) {
    using std::cout;
    using std::cerr;

    if (argc < 2) {
        cout << "Missing required argument: type" << std::endl;
        return 1;
    }
    char *type = argv[1];
    char library_file[255];

    sprintf(library_file, "./%s.so", type);

    // load the triangle library
    void* shape = dlopen(library_file, RTLD_LAZY);
    if (!shape) {
        cerr << "Cannot load library: " << dlerror() << '\n';
        return 1;
    }

    // reset errors
    dlerror();
    
    // load the symbols
    create_t* create_shape = (create_t*) dlsym(shape, "create");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        return 1;
    }
    
    destroy_t* destroy_shape = (destroy_t*) dlsym(shape, "destroy");
    dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
        return 1;
    }

    // create an instance of the class
    polygon* poly = create_shape();

    // use the class
    poly->set_side_length(7);
        cout << "The area is: " << poly->area() << '\n';

    // destroy the class
    destroy_shape(poly);

    // unload the triangle library
    dlclose(shape);
}