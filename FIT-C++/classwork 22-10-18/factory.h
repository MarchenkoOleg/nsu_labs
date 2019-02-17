//
// Created by march on 22.10.2018.
//
#include "Unit.h"
#include <map>
#include <string>
#include <vector>

#include "Unit.h"
#include "Marine.h"
#include "BattleCruiser.h"
#include "Zealot.h"

//forward declaration
/*class Unit;
namespace std {
    class string;
}*/
// end forward declaration

#ifndef CLASSWORK_22_10_18_FACTORY_H
#define CLASSWORK_22_10_18_FACTORY_H

template<class Id, class Unit, class Creator>
class Factory {
public:
    //typedef Unit * (*creator_t)();
    //typedef std::string Id;

    Unit *createUnitById(const Id &id) {
        auto it = creators.find(id);
        if(creators.end() == it)
            return nullptr; //
        return it->second(); // вызывается creator
    }
    bool registerUnit(const Id &id, Creator const creator) {
        creators[id] = creator;
        return true;
        // TODO: check twice register
    }
    static Factory* getInstance() {
        static Factory factory;
        return &factory;
    }
private:
    Factory() = default;
    Factory(const Factory &) = delete;
    Factory &operator=(const Factory &) = delete;
    std::map<std::string, Creator> creators;
};

#endif //CLASSWORK_22_10_18_FACTORY_H
