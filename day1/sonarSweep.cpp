//Patrick Woodworth

//Imports
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int part1(vector<int>);
int part2(vector<int>);

int main(int argc, char const *argv[]){
   
    vector<int> depthVector;
    string temp;

    ifstream inputFile;
    inputFile.open("inputFile.txt");

    while(getline(inputFile, temp)){
        depthVector.push_back(stoi(temp));
    }

    cout << "Total that are larger than previous: " << part1(depthVector) << endl;
    cout << "Total sliding windows that are larger than previous: " << part2(depthVector) << endl;

    return 0;
}

//Checks how many increases there are in the entire vector
int part1(vector<int> depthVector) {
    int counter = 0;
    for (int i = 1; i < depthVector.size(); i++) {
        if(depthVector[i-1] < depthVector[i]){
            counter++;
        } 
    }
    return counter;
}

/*
    Checks to see if the sum of a sliding window increases 
    Every 3 are part of a sliding window, overlapping
    If not enough for a full sliding window of 3, stop
*/
int part2(vector<int> depthVector){
    int counter = 0;
    int setOne = 0;
    int setTwo = 0;
    //Loop starts at start of second sliding window
    for (int i = 0; i < depthVector.size() - 2; i++){
        setOne = depthVector[i] + depthVector[i + 1] + depthVector[i + 2];
        cout << depthVector[i] << "+" << depthVector[i + 1] << "+" << depthVector[i + 2] << endl;;
        cout << setOne << endl;
        if(setOne > setTwo){
            counter++;
        }

        setTwo = setOne;
    }

    return counter;
}