#include <list>
#include <iostream>
#include <vector>
#include <fstream>

#include "LinearProbing.hpp"

using namespace std;

int numero_colisoes = 0;

LinearProbingHash::LinearProbingHash(int table_size){
    this->TABLE_SIZE = table_size;

    this->sz = 0;

    arr = new HashNode* [TABLE_SIZE];

    //Init all alements as NULL
    for (int i = 0 ; i < TABLE_SIZE ; i++)
        arr[i] = NULL;

    // Dummy node with key (string) and value (int) -1
    dummy = new HashNode("-1", -1);

}

void LinearProbingHash::insertKey(string key, int value){

    HashNode *temp = new HashNode(key, value);

    int index = hashFunction(key);

    // Find next free space (probing)
    while (arr[index] != NULL && arr[index]->key != key && arr[index]->key != "-1"){
        numero_colisoes++;
        index++;
        index %= TABLE_SIZE;
    }

    // Valid position
    if (arr[index] == NULL || arr[index]->key == "-1")
        sz++;

    arr[index] = temp; 
}

int LinearProbingHash::deleteKey(string key){

    int index = hashFunction(key);

    // Finding the node with given key
    while (arr[index] != NULL){
        // if node found
        if (arr[index]->key == key){
            HashNode *temp = arr[index];

            // INsert dummy node
            arr[index] = dummy;

            sz--;

            return temp->value;
        }
        index++;
        index %= TABLE_SIZE;
    }

    // If not found return -2
    return -2;
}

// return -2 if the key is not found, else return count
int LinearProbingHash::searchKey(string key){
    int index = hashFunction(key);

    int count = 0;

    // find node with given key
    while (arr[index] != NULL){

        // Avoid infinite loop
        if (count++ > TABLE_SIZE)
            return -2;

        // If the key has been found
        if (arr[index]->key == key)
            return count;

        index++;
        index %= TABLE_SIZE;
    }

    // If not found return -2
    return -2;
}

void LinearProbingHash::printHashTable(){
    for (int i = 0 ; i < TABLE_SIZE ;i++)
        if (arr[i] != NULL && arr[i]->key != "-1")
            cout << "key = " << arr[i]->key << " value = " << arr[i]->value << endl;
}

float LinearProbingHash::taxaOcupacao(){
    float vazio = 0;
    for (int i = 0 ; i < TABLE_SIZE; i++)
        if (arr[i] == NULL || arr[i]->key == "-1")
            vazio++;
    return 1 - (vazio/TABLE_SIZE);
} 

int LinearProbingHash::numeroColisoes(){
    return numero_colisoes;
}

vector<string> LinearProbingHash::retornaAchados(string nome_arqv_cons){
    fstream file;
    string name;

    string comMaiorConsultas;
    string comMenorConsultas;

    vector<string> names;
    vector<string> achados;

    int maior = 0;
    int menor = 10000;
    int media = 0;

    // armazena em names os nomes retirados do arquivo passado para serem consultados
    file.open(nome_arqv_cons);
    while(getline(file, name)){
        names.push_back(name);
    }
    file.close();

    // ideia de comparação
    int i = 0;
    for(i = 0; i < names.size(); i++){
        int flag = searchKey(names[i]);
        if(flag != -2)
        {
            achados.push_back(names[i]);
            if(maior < flag){
                maior = flag;
                comMaiorConsultas = names[i];
            }
            if(menor > flag){
                menor = flag;
                comMenorConsultas = names[i];
            }
            media += flag;
        }
    }

    cout << endl;
    cout << "Nome com maior consultas: " << comMaiorConsultas << " - " << maior << " consultas" << endl;
    cout << "Nome com menor consultas: " << comMenorConsultas << " - " << menor << " consultas" << endl;
    cout << "Media de acessos: " << media / (i - 1);
    cout << endl;

    return achados;
}

vector<string> LinearProbingHash::retornaNaoAchados(string nome_arqv_cons){
    fstream file;
    vector<string> names;
    string name;

    vector<string> naoAchados;

    // armazena em names os nomes retirados do arquivo passado para serem consultados
    file.open(nome_arqv_cons);
    while(getline(file, name)){
        names.push_back(name);
    }
    file.close();

    // ideia de comparação
    for(int i = 0; i < names.size(); i++)
        if(searchKey(names[i]) == -2)
            naoAchados.push_back(names[i]);

    return naoAchados;
}