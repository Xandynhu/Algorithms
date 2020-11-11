#ifndef FINAL_CUBES
#define FINAL_CUBES

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_set>

using namespace std;

// minterms working functions
    vector<vector<int>> sortCubes(vector<int> collection);
    unordered_set<int> matches(vector<vector<int>> sorted, unordered_set<int> &used, int nVar);

// function to convert a normal decimal into a decimal that can be analysed
// 13 == 1101 (can not be analysed -> -1 in code)
// transforms 13 == 1101 == 1 1 0 1 into 01 01 10 01 == 01011001
    vector<int> normDec_to_workDec(vector<int> input, int nVar);

// main function that analyses n minterms and returns the respective cubes
// cubes returned form: 01, 10, 11
    unordered_set<int> finalCubes(vector<int> minterms,int nVar);

#endif