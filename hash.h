#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class hashClass
{
private:
    static const int tableSize = 4;

    struct item
    {
        string name;
        string address;
        item* next;
    };

    item* HashTable[tableSize];

public:
    hashClass();
    int Hash(const string& key);
    void AddItem(const string& name, const string& address);
    int NumberOfItemsInIndex(const int& index);
    void PrintTable();
    void PrintItemsInIndex(const int& index);
    void FindAddress(const string& name);
    void RemoveItem(const string& name);
};

#endif