#include <iostream>
#include <vector>
#include "HashTable.h"
#include "gtest/gtest.h"


/*
TEST(HachTableTests, TestName) {
    EXPECT_EQ(1, 1);
}
*/


int main() {
    std::cout << "Main Start" << std::endl;
    HashTable MyHashTable1(10);
    HashTable MyHashTable2(MyHashTable1);
    HashTable MyHashTable3(15);
    HashTable MyHashTable4 = MyHashTable3;

    std::cout << "MyHashTable1 size: " << MyHashTable1.size() << std::endl;
    std::cout << "MyHashTable2 size: " << MyHashTable2.size() << std::endl;
    std::cout << "MyHashTable3 size: " << MyHashTable3.size() << std::endl;
    std::cout << "MyHashTable4 size: " << MyHashTable4.size() << std::endl;

    MyHashTable2.swap(MyHashTable4);

    std::cout << "MyHashTable1 size: " << MyHashTable1.size() << std::endl;
    std::cout << "MyHashTable2 size: " << MyHashTable2.size() << std::endl;
    std::cout << "MyHashTable3 size: " << MyHashTable3.size() << std::endl;
    std::cout << "MyHashTable4 size: " << MyHashTable4.size() << std::endl;

    std::cout << "Main End" << std::endl;
    return 0;
}