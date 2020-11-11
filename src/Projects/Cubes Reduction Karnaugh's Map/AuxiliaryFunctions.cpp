#include "AuxiliaryFunctions.hpp"

void printVector(vector<int> input){
    for(int i : input)
        cout << i << " ";
    cout << endl;
}

void printUnordered_set(unordered_set<int> input){
    for(int i : input)
        cout << i << " ";
    cout << endl;
}

// converts a binary number to its decimal form in int format
int binaryToDecimal_int(string input){
    int value = 0;

    for(int i = input.size() - 1; i >= 0; i--){
        if(input[i] == '1')
            value += pow(2, input.size() - 1 - i);
        else
            if(input[i] != '0')
                return -1;
    }

    return value;
}

// converts a binary number to its decimal form in string format
string binaryToDecimal_string(string input){
    int value = 0;

    for(int i = input.size() - 1; i >= 0; i--){
        if(input[i] == '1')
            value += pow(2, input.size() - 1 - i);
        else
            if(input[i] != 0)
                return "erro";
    }

    return to_string(value);
}

// converts a text code to a binary number in string format
string codeTextToBinary(string input){
    string output(input.size() * 2, '0');

    for(int i = 0, j = 0; i < input.size(); i++, j += 2){
        if(input[i] == '0'){
            output[j] = '1';
            output[j+1] = '0';
        }
        else if(input[i] == '1'){
            output[j] = '0';
            output[j+1] = '1';
        }
        else if(input[i] == '-'){
            output[j] = '1';
            output[j+1] = '1';
        }
    }

    return output;
}

vector<int> unordered_to_vector(unordered_set<int> input){
    vector<int> output1, output2;

    for(int i : input)
        output1.push_back(i);

    for(int i : output1)
        output2.push_back(i);

    return output2;
}

vector<string> decimalToCode(vector<int> input, int nVar){
    vector<string> output;

    for(int i : input){
        string str;
        for(int j = 0; j < nVar; j++){
            if(i & 1)
                str = "01" + str; 
            else
                str = "10" + str;  
            i = i >> 1;
        }
        output.push_back(str);
    }

    return output;
}

unordered_set<int> vector_to_unordered(vector<int> input){
    unordered_set<int> output1, output2;

    for(int i : input)
        output1.insert(i);

    for(int i : output1)
        output2.insert(i);

    return output2;
}

// calculates the quantity of '01's in the binary form of a int recived in decimal
int quantityOf_01(int n){
    int flag, count = 0;

    while(n){
        flag = n & 3;
        n = n >> 2;

        if(flag == 1)
            count++;
    }

    return count;
}

int quantityOf_10(int n){
    int flag, count = 0;

    while(n){
        flag = n & 3;
        n = n >> 2;

        if(flag == 2)
            count++;
    }

    return count;
}
int quantityOf_11(int n){
    int flag, count = 0;

    while(n){
        flag = n & 3;
        n = n >> 2;

        if(flag == 3)
            count++;
    }

    return count;
}