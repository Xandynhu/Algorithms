#include <list>
#include <iostream>

#include "SeparateChaining.hpp"

using namespace std;

SeparateChainingHash::SeparateChainingHash(int sz){
    this->TABLE_SIZE = sz;
    table = new list<string>[TABLE_SIZE];
}


void SeparateChainingHash::insertKey(string key){
    int index = hashFunction(key); // Get the hash index

    table[index].push_back(key); // Insert 'key' to the linked list at 'index'
}

void SeparateChainingHash::deleteKey(string key){

    int index = hashFunction(key); // Get the hash index

    // Find the key in the list
    list<string>::iterator i;
    for (i = table[index].begin() ; i != table[index].end() ; i++){
        if (*i == key) // The key has been found
            break;
    }

    // If the key is found in hash table, delete it
    if (i != table[index].end())
        table[index].erase(i);
}

void SeparateChainingHash::printHashTable(){
    for (int i = 0 ; i < TABLE_SIZE ; i++){
        cout << i;
        for (auto x : table[i])
            cout << "-->" << x;
        cout << endl;
    }
}

float SeparateChainingHash::taxaOcupacao(){
    float vazio = 0;
    for (int i = 0 ; i < TABLE_SIZE; i++)
        if (table[i].empty())
            vazio++;
    return 1 - (vazio/TABLE_SIZE);
} 

int SeparateChainingHash::numeroColisoes(){
    int colisoes = 0;
    for (int i = 0 ; i < TABLE_SIZE; i++)
        if (!table[i].empty())
            colisoes += table[i].size()-1;
    return colisoes;
}