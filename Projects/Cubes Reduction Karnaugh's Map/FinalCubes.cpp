#include "FinalCubes.hpp"
#include "AuxiliaryFunctions.hpp"

// generate a int matrix with cubes sorted by the quantiy of '01's
vector<vector<int>> sortCubes(vector<int> collection){
    int greater = 0;

    // returns in 'greater' the largest amount of "01"s in a single minterm
    for(int minterm : collection){
        int n = quantityOf_01(minterm);
        if(n > greater)
            greater = n;
    }

    // define a matrix with the same lines quantities of greater
    vector<vector<int>> sorted(greater + 1);

    for(int minterm : collection)
        sorted[quantityOf_01(minterm)].push_back(minterm);

    return sorted;
}

// returns a unordered_set list of integers that are close to each others reciving a sorted matrix
unordered_set<int> matches(vector<vector<int>> sorted, unordered_set<int> &used, int nVar){
    unordered_set<int> close, visited;

    for(int i = 0; i < sorted.size() - 1; i++){
        for(int cube1 : sorted[i]){
            for(int cube2 : sorted[i+1]){
                int count = 0;
                int mask = 3;
                
                for(int n = 0; n < nVar; n++){
                    if((cube1 & mask) != (cube2 & mask))
                        count++;
                    mask = mask << 2;
                }

                if(count == 1){
                    visited.insert(cube1);
                    visited.insert(cube2);

                    if(used.count(cube1 | cube2) == 0){
                        close.insert(cube1 | cube2);
                        used.insert(cube1 | cube2);
                    }
                }
            }
        }
    }
    if(visited.size() == 0)
        return close;

    for(int i = 0; i < sorted.size(); i++)
        for(int cube : sorted[i])
            if(visited.count(cube) == 0)
                close.insert(cube);

    return close;
}

vector<int> normDec_to_workDec(vector<int> input, int nVar){
    vector<int> output;
    vector<string> aux = decimalToCode(input, nVar);

    for(int i = 0; i < aux.size(); i++)
        output.push_back(binaryToDecimal_int(aux[i]));

    return output;
}

unordered_set<int> finalCubes(vector<int> minterms,int nVar){
    vector<vector<int>> sorted = sortCubes(minterms);
    unordered_set<int> used, ret;
    unordered_set<int> close = matches(sorted, used, nVar);
    
    ret = close;

    while(close.size() > 0){
        ret = close;
        sorted = sortCubes(unordered_to_vector(close));
        close = matches(sorted, used, nVar);
    }

    return ret;
}