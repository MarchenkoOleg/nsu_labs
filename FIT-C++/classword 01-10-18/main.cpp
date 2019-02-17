#include <iostream>
#include <stdlib.h>
#include <time.h>

// базовый класс
class Base {
public:
    virtual void f() {
        std::cout << "Base::f()" << std::endl;
    }
};

// класс наследник
class Derived : public Base {
public:
    void f() {
        std::cout << "Derived::f()" << std::endl;
    }
};
class AnotherDerived : public Base {
public:
    void f() {
        std::cout << "AnotherDerived::f()" << std::endl;
    }
};
void virtualTest(Base * b) {
    b->f();
}

int main() {
    srand(time(0));

    Base * b1; // = new Derived;
    // Base * b2 = new AnotherDerived;
    if(rand() % 2) {
        b1 = new Derived;
    } else {
        b1 = new AnotherDerived;
    }
    virtualTest(b1);
/*
 * void MoveAllUnits(std::vector<Unit *> units) {
 *
     * for(Unit * u : units) {
     *  u->move();
     * }
    }
    virtualTest(b2);
*/
    return 0;
}