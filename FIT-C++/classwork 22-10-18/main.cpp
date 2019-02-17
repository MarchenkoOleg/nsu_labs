#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

#include "factory.h"
#include "Unit.h"

//extern Factory<std::string> factory;

void moveAll(const std::vector<Unit *> units) {
    for( Unit * u : units) {
        u->move(0, 0);
    }
}

int main(int argc, char ** argv) {
    if(argc < 2) {
        std::cout << "No unit specified!" << std::endl;
        return -1;
    }


    //Factory f;
    std::vector<Unit *> units;
    for(int i = 1; i <argc; ++i) {
        auto factory = Factory<std::string,
        Unit,
        Unit* (*) ()>::getInstance();
        Unit * u = factory->createUnitById(argv[i]);
        if(nullptr == u) {
            std::cerr << "Unknown unit: " << argv[i] << std::endl;
        }
        units.push_back(u);
    }
    moveAll(units);

    for(Unit * u :units) delete u;

}