//
// Created by march on 22.10.2018.
//

#include "Zealot.h"
#include <iostream>
#include <string>
#include "factory.h"

namespace {
    Unit * createZealot() {
        return new Zealot;
    }

    bool b = Factory<std::string, Unit, Unit* (*) ()>::getInstance()->registerUnit("Zealot", createZealot);
}


void Zealot::move(int x, int y) {
    std::cout << "Zealot move!" << std::endl;
}


