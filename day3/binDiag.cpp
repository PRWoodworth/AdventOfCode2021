//Patrick Woodworth

//Imports
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
    string temp, mcd, lcd;
    vector<string> binaryInput;
    vector<int> numOnes, numZeroes;
    ifstream inputFile;
    inputFile.open("inputFile.txt");
    inputFile >> temp;
    while(getline(inputFile, temp)){
        binaryInput.push_back(temp);
    }
    int numBits = temp.length();
    numOnes.resize(numBits);
    numZeroes.resize(numBits);

    //Get number of 0s and 1s in each column
    for (int i = 0; i < binaryInput.size(); i++){
        for (int k = 0; k < numBits; k++){
            switch (int(binaryInput[k][i]-'0')){
            case 0:
                numZeroes[k]++;
                break;
            case 1:
                numOnes[k]++;
                break;
            default:
                break;
            }
        }
    }
    //Construct binary representation of gamma rate
    for (int j = 0; j < numBits; j++){
        if (numZeroes[j] > numOnes[j]){
            mcd.append("0");
        } else if (numZeroes[j] < numOnes[j]){
            mcd.append("1");
        }
    }
    cout << mcd << endl;
    

    inputFile.close();
    return 0;
}