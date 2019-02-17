//
// Created by march on 22.10.2018.
//

#include "BattleCruiser.h"
#include <iostream>
#include <string>
#include "factory.h"

namespace {
    Unit *createBattleCruiser() {
        return new BattleCruiser;
    }

    bool b = Factory<std::string, Unit, Unit* (*) ()>::getInstance()->registerUnit("BattleCruiser", createBattleCruiser);
}


void BattleCruiser::move(int x, int y) {
    std::cout << "BattleCruiser move!" << std::endl;
}


