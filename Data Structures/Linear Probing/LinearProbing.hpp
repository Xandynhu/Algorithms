#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include <list>
#include <cmath>
#include <vector>

using namespace std;

class HashNode{
    public:
        int value;
        string key;

    HashNode(string key, int value){// Constructor
        this->value = value;
        this->key = key;
    } 

};


class LinearProbingHash{
    
    private:
        // Hash element array
        HashNode **arr;
        int TABLE_SIZE;

        // Current size
        int sz;
        
        // Dommy node
        HashNode *dummy;

    public:
    
        LinearProbingHash(int table_size);

        unsigned hashCode(string key){
            unsigned hash = 0;
            for (int i = 0 ; i < key.length() ; i++)
                hash = key[i] + (31 * hash);
            return hash;
        }

        // Hash function from map values to (hash) key
        int hashFunction(string s){
            int index = 0;
            unsigned hash_code = hashCode(s);

            index = (hash_code & 0x7fffffff) % TABLE_SIZE;

            return index;
        }

        void insertKey(string key, int value);

        int  deleteKey(string key);

        int searchKey(string key);

        void printHashTable();

        float taxaOcupacao();

        int numeroColisoes();

        vector<string> retornaAchados(string nome_arqv_cons);

        vector<string> retornaNaoAchados(string nome_arqv_cons);
};


#endif