//
// Created by march on 22.09.2018.
//
#include <vector>
#include <iostream>
#include <string>
#include "HashTable.h"

HashTable::HashTable(int size) {
    std::cout << "Constructor 1" << std::endl;
    table_size = size;
}

HashTable::~HashTable() {
    std::cout << "Destructor" << std::endl;
}

int HashTable::size() const {
    return table_size;
}

HashTable::HashTable(const HashTable &b) {
    std::cout << "Constructor 2" << std::endl;
    table_size = b.table_size;
}

HashTable &HashTable::operator=(const HashTable &b) {
    table_size = b.table_size;
    std::copy(b.table.begin(), b.table.end(), table.begin());
    return *this;
}


void HashTable::swap(HashTable &b) {
    /* copy in buffer */
    int table_size_buf = b.table_size;
    std::vector<Node> table_buf;
    std::copy(b.table.begin(), b.table.end(), table_buf.begin());
    /* copy data to b */
    b.table_size = table_size;
    b.table.clear();
    std::copy(table.begin(), table.end(), b.table.begin());
    /* copy data from buffer */
    table_size = table_size_buf;
    table.clear();
    std::copy(table_buf.begin(), table_buf.end(), table.begin());
}

void HashTable::clear() {
    table.clear();
    table_size = 0;
}
/*



bool HashTable::erase(const Key &k) {
    return false;
}

bool HashTable::insert(const Key &k, const Value &v) {
    return false;
}

bool HashTable::contains(const Key &k) const {
    return false;
}

Value &HashTable::operator[](const Key &k) {
    return <#initializer#>;
}

Value &HashTable::at(const Key &k) {
    return <#initializer#>;
}

const Value &HashTable::at(const Key &k) const {
    return <#initializer#>;
}



bool HashTable::empty() const {
    return false;
}
*/

