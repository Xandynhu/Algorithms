#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>

#include "LinearProbing.hpp"

using namespace std;

// Global Variables
int empty_rate;

void printVector(vector<string> a){
    for (int i  = 0 ; i < a.size() ; i++)
        cout << a[i] << endl;
    cout << endl;
}

bool isPrime(int n){
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i=5 ; i*i <= n ; i = i+6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int nextPrime(int n){
    if (n <= 1)
        return 2;

    int prime = n;
    bool found = false;

    while (!found){
        prime++;

        if (isPrime(prime))
            found = true;
    }

    return prime;
}

int readFile(string file_name, vector<string> *names){
    fstream file;
    string line, word;
    int out = 0;
    file.open(file_name);

    while(getline(file, word)){
        names->push_back(word);
    }
    out = names->size();
    file.close();

    return out;
}

int main(){
    fstream nomes;
    fstream consultas;
    string entrada1 = "../data/nomes_10000.txt";
    string entrada2 = "../data/consultas.txt";

    vector<string> names;

    if (!readFile(entrada1, &names)){
        cout << "Erro na leitura do arquivo!" << endl;
        cout << "===========================" << endl << endl;

        exit (1);
    }

    int n = names.size();
    int table_size = nextPrime(n);

    LinearProbingHash h = LinearProbingHash(table_size);


    //---------------------------------------------------------
    //                 LINEAR PROBING HASH
    //---------------------------------------------------------

        printVector(names);
        for (int i = 0 ; i < n ; i++)
            h.insertKey(names[i], i+1);

        h.printHashTable();

    //---------------------------------------------------------

    cout << endl << endl << endl;

    cout << "TAXA DE OCUPACAO LINEAR PROBING HASH: " << h.taxaOcupacao() << endl;
    cout << "NUMERO DE COLISOES LINEAR PROBING HASH: " << h.numeroColisoes() << endl;

    cout << "VETOR DE PALAVRAS ACHADAS:" << endl;
    printVector(h.retornaAchados(entrada2));

    cout << "VETOR DE PALAVRAS NAO ACHADAS" << endl;
    printVector(h.retornaNaoAchados(entrada2));

    return 0;
}