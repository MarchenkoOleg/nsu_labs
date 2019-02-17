//
// Created by march on 22.10.2018.
//

#include "Marine.h"
#include <iostream>
#include <string>
#include "factory.h"

namespace {
    Unit *createMarine() {
        return new Marine;
    }

    bool b = Factory<std::string,
    Unit,
    /*decltype(createMarine)*/ Unit* (*) ()>::getInstance()->registerUnit("Marine", createMarine);
}


void Marine::move(int x, int y) {
    std::cout << "Marine move!" << std::endl;
}


