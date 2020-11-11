#ifndef AUXILIARY_FUNCTIONS_H
#define AUXILIARY_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

// print func
    void printVector(vector<int> input);
    void printUnordered_set(unordered_set<int> input);

// convertion func
    int binaryToDecimal_int(string input);
    string binaryToDecimal_string(string input);
    string codeTextToBinary(string input);
    vector<int> unordered_to_vector(unordered_set<int> input);
    vector<string> decimalToCode(vector<int> input, int nVar);
    unordered_set<int> vector_to_unordered(vector<int> input);

// minterms operations
    int quantityOf_01(int n);
    int quantityOf_10(int n);
    int quantityOf_11(int n);


#endif