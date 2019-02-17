#include <iostream>

struct A {

};

struct SmartPtrData {
    size_t counter = 0u;
    A * ptr = nullptr;
};
// по желанию: template <class T>

class SmartPointer {
public:
    ~SmartPointer() { // д-р по умолчанию
        if(nullptr != spdata) {
            if(1 == spdata->counter) {
                delete spdata->ptr;
                delete spdata;
                return;
            }
            --spdata->counter;
        }
    }
    //SmartPointer(A * a ) {} // к-р по умолчанию
    SmartPointer(A * a = nullptr) {
        spdata = new SmartPtrData;
        if(a != nullptr) {
            spdata->ptr = a;
            spdata->counter = 1;
        } else {
            spdata->ptr = new A;
        }
    } // к-р захватывает ресурс
    SmartPointer(const SmartPointer& other) { // к-р копирования
        if(other.spdata != nullptr) {
            spdata->ptr = other.spdata->ptr;
            other.spdata->counter++;
        } else {

        }
    }
    SmartPointer& operator=(const SmartPointer& other); // оп-я присваивания
    // по желанию: поддержать семантику перемещения

    A * get(); // получить указатель
    void reset(A * other); // освободить старый ресурс, захватить новый

    // operator*, operator->
private:
    SmartPtrData * spdata = nullptr;
};

int main() {
    SmartPointer sp(new int);

    SmartPointer sp2 = sp;
    // вариант 1: разрушающее копирование (std::auto_ptr)
    // вариант 2: глобальная хэш-таблицы хранит флажки про каждый ресурс
    // вариант 3: флажок хранить прямо на месте (std::shared_ptr)
    // вариант 4: linked_ptr (chromium)
    // вариант 5: счетчик ссылок хранить прямо в объекте (boost::intrusive_ptr, refcounted в chromium)
    // вариант 6: запретить копирование (boost::scoped_ptr)
    // вариант 7: запретить копирование, но разрешить перемещение (std::unique_ptr)
    return 0;
}