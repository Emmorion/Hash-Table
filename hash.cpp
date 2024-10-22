#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

hashClass::hashClass()
{
    for (int i = 0; i < tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->address = "empty";
        HashTable[i]->next = NULL;
    }
}

void hashClass::AddItem(const string& name, const string& address)
{
    int index = Hash(name);

    if (HashTable[index]->name == "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->address = address;
    }
    else
    {
        item* ptr = HashTable[index];
        item* new_ptr = new item;
        new_ptr->name = name;
        new_ptr->address = address;
        new_ptr->next = NULL;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_ptr;
    }
}

int hashClass::NumberOfItemsInIndex(const int& index)
{
    int count = 0;

    if (HashTable[index]->name == "empty")
    {
        return count;
    }
    count++;
    item* ptr = HashTable[index];
    while (ptr->next != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}

void  hashClass::PrintTable()
{
    int number;

    for (int i = 0; i < tableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        cout << "index: " << i << "; name: " << HashTable[i]->name << "; address: " << HashTable[i]->address << "; number of items: " << number << endl;

    }
}

void hashClass::PrintItemsInIndex(const int& index)
{
    item* ptr = HashTable[index];

    if (ptr->name == "empty")
    {
        cout << "index = " << index << " is empty." << endl;
    }
    else
    {
        cout << "index " << index << " contains the following item(s):" << endl;

        while (ptr != NULL)
        {
            cout << "name: " << ptr->name << "; address: " << ptr->address << endl;
            ptr = ptr->next;
        }
    }
}

int hashClass::Hash(const string& key)
{
    int hash = 0;
    int index;

    for (int i = 0; i < key.length(); i++)
    {
        hash = hash + (int)key[i] * 17;
    }

    index = hash % tableSize;

    return index;
}

void hashClass::RemoveItem(const string& name)
{
    int index = Hash(name);

    item* del_ptr; 
    item* ptr1;
    item* ptr2;

    if (HashTable[index]->name == "empty" && HashTable[index]->address == "empty")
    {
        cout << name << " was not found in Hash Table" << endl;
    }
    else if (HashTable[index]->name == name && HashTable[index]->next == NULL)
    {
        HashTable[index]->name = "empty";
        HashTable[index]->address = "empty";

        cout << name << " was removed from the Hash Table" << endl;
    }
    else if (HashTable[index]->name == name)
    {
        del_ptr = HashTable[index];
        HashTable[index] = HashTable[index]->next;

        delete del_ptr;

        cout << name << " was removed from the Hash Table" << endl;
    }
    else
    {
        ptr1 = HashTable[index]->next;
        ptr2 = HashTable[index];

        while (ptr1 != NULL && ptr1->name != name)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        if (ptr1 == NULL)
        {
            cout << name << " was not found in Hash Table" << endl;
        }
        else
        {
            del_ptr = ptr1;
            ptr1 = ptr1->next;
            ptr2->next = ptr1;

            delete del_ptr;
            cout << name << " was removed from the Hash Table" << endl;
        }
    }
}

void hashClass::FindAddress(const string& name)
{
    int index = Hash(name);
    bool foundName = false;
    string address;

    item* ptr = HashTable[index];
    while (ptr != NULL)
    {
        if (ptr->name == name)
        {
            foundName = true;
            address = ptr->address;
        }
        ptr = ptr->next;
    }
    if (foundName == true)
    {
        cout << "Residential address is " << address << endl;
    }
    else
    {
        cout << name << "'s address wasn't found in the Hash Table" << endl;
    }
}