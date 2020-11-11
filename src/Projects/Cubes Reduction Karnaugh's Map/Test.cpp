#include "AuxiliaryFunctions.hpp"
#include "FinalCubes.hpp"
#include "MintermsIn.hpp"

using namespace std;

void testFinalCubes(){

    cout << "=========================================" << endl;
    cout << "      FINAL MATCHES BY SOME MINTERMS     " << endl;
    cout << "=========================================" << endl;

    unordered_set<int> final;
    vector<int> input, input1;
    vector<string> minterms_str;
    string aux1;

    input.push_back(1);
    input.push_back(3);
    input.push_back(2);
    input.push_back(6);
    input.push_back(7);
    int nVar = 3;

    final = finalCubes(normDec_to_workDec(input, nVar), nVar);

    cout << "cubes: ";
    printUnordered_set(final);
    cout << endl;
}

int main(){

    // final cubes func test
    testFinalCubes();
    
    return 0;
}