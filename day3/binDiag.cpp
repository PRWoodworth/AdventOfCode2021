//Patrick Woodworth

//Imports
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
    string temp, mcd = "", lcd = "";
    int gammaRate = 0, epsilonRate = 0;
    vector<string> binaryInput;
    vector<int> numOnes, numZeroes;
    ifstream inputFile;
    inputFile.open("inputFile.txt");
    while(getline(inputFile, temp)){
        binaryInput.push_back(temp);
    }
    int numBits = temp.length();
    numOnes.resize(numBits);
    numZeroes.resize(numBits);

    //Get number of 0s and 1s in each column
    for (int i = 0; i < binaryInput.size(); i++){
        for (int k = 0; k < numBits; k++){
           if (binaryInput[k][i] == '0'){
                numZeroes[k]++;
            } else {
                numOnes[k]++;
            }
        }
    }
    //Construct binary representation of gamma rate
    for (int j = 0; j < numBits; j++){
        cout << "# 0s at bit " << j << ": " << numZeroes[j] << endl;
        cout << "# 1s at bit " << j << ": " << numOnes[j] << endl;
        if (numZeroes[j] > numOnes[j]){
            mcd += "0";
            lcd += "1";
        } else if (numZeroes[j] < numOnes[j]){
            mcd += "1";
            lcd += "0";
        }
    }
    cout << mcd << endl;
    cout << lcd << endl;




    inputFile.close();
    return 0;
}