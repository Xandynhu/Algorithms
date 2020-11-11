#include "AuxiliaryFunctions.hpp"
#include "FinalCubes.hpp"

using namespace std;

int main(){
    
    unordered_set<int> final;
    vector<int> input;

    // puts in the vector the integers you want to represent the "true lines"
    input.push_back(1);
    input.push_back(3);
    input.push_back(2);
    input.push_back(6);
    input.push_back(7);

    // nVar = numb of variables of the largest input (a, b, c, d...)
    // 7 is the largest, 7(dec) = 111(bin)
    // variables used = a, b, c
    // nVar = 3
    int nVar = 3;

    final = finalCubes(normDec_to_workDec(input, nVar), nVar);

    cout << "cubes: ";
    printUnordered_set(final);
    cout << endl;
    
    return 0;
}