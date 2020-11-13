#ifndef SEPARATECHAINING_H
#define SEPARATECHAINING_H

#include <list>
#include <cmath>

using namespace std;

// Hash Map, using separate chaining, declaration
class SeparateChainingHash{

    // Data members can be accessed using methods
    private:
        int TABLE_SIZE;
        list<string> *table; // Pointer to an array containing the lists
    
    // Methods
    public:

        SeparateChainingHash(int sz); // Constructor
        
        // Inserts a key into hash table
        void insertKey(string x);

        // Deletes a key from hash table
        void deleteKey(string x);

        // Calculates the ocupation rate
        float taxaOcupacao();

        int numeroColisoes();

        unsigned hashCode(string s){
            unsigned hash = 0;
            for (int i = 0 ; i < s.length() ; i++)
                hash = s[i] + (31 * hash);
            return hash;
        }

        // Hash function from map values to (hash) key
        int hashFunction(string s){

            int index = 0;
            unsigned hash_code = hashCode(s);

            index = (hash_code & 0x7fffffff) % TABLE_SIZE;

            return index;
        }

        int getTableSize(){
            return this->TABLE_SIZE;
        }


        void printHashTable();

};

#endif