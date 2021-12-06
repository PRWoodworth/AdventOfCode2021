//Patrick Woodworth

//Imports
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string o2filtering(vector<string>, string);
string co2filtering(vector<string>, string);

int main(int argc, char const *argv[]){
    string temp, mcd = "", lcd = "";
    int gammaRate = 0, epsilonRate = 0, powerConsumption = 0;
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
           if (binaryInput[i][k] == '0'){
                numZeroes[k]++;
            } else {
                numOnes[k]++;
            }
       }
    }
    //Construct binary representation of gamma rate
    for (int j = 0; j < numBits; j++){
        if (numZeroes[j] > numOnes[j]){
            mcd += "0";
            lcd += "1";
        } else if (numZeroes[j] < numOnes[j]){
            mcd += "1";
            lcd += "0";
        }
    }
    powerConsumption = (stoi(mcd, nullptr, 2)) * (stoi(lcd, nullptr, 2));
    cout << "Power consumption: " << powerConsumption << endl;
    string o2rating = o2filtering(binaryInput, mcd);
    string co2rating = co2filtering(binaryInput, lcd);
    inputFile.close();
    return 0;
}

string o2filtering(vector<string> binaryInput, string mcd){
    //Filter numbers out of binaryInput based on MCD
    //Iterate through each bit, filter out numbers that don't have that MCD at that bit
    string o2rating;
    for (int i = 0; i < mcd.length(); i++){
        for (int j = 0; j < binaryInput.size(); j++){
            //if digit of MCD does not match digit of binaryInput AT THE SAME BIT, remove that entire binaryInput entry
            
        }
    }
    
    return o2rating;
}

string co2filtering(vector<string> binaryInput, string lcd){
    //Filter numbers out of binaryInput based on LCD
    //Iterate through each bit, filter out numbers that don't have that LCD at that bit
    string co2rating;
    
    return co2rating;
}