#include <iostream>

struct Object {
    int t;
};

class SmartPointer {
public:
    SmartPointer(Object * o) : o_(o) {}
    ~SmartPointer() {
        std::cout << "Destructor" << std::endl;
    }
    SmartPointer(SmartPointer& other) {
        o_ = other.o_;
        other.o_ = nullptr;
    }
    SmartPointer & operator=(SmartPointer& other) {
        if(&other != this) {
            delete o_;
            o_ = other.o_;
            other.o_ = nullptr;
        }
        return *this;
    }
    printT() {
        std::cout << "t = " << o_->t << std::endl;
    }
private:
    Object * o_ = nullptr;
};


int main() {
    Object * o1 = new Object();
    o1->t = 1;
    /// провал
    SmartPointer sp1(o1);
    sp1.printT();
    // OK! sp автоматически удалит объект
    //SmartPointer sp2 = sp;
    // sp2 теперь владеет объектом, а sp не владеет
    SmartPointer sp3(new Object());
    //sp2 = sp3;
    // sp2 подчистил свой объект и владеет объектом из sp3
    return 0;
}