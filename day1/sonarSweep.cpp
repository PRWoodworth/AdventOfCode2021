//Patrick Woodworth

//Imports
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void part1(vector<int>);
void part2(vector<int>);

int main(int argc, char const *argv[]){
   
    vector<int> depthVector;
    int holder = 0;

    ifstream inputFile;
    inputFile.open("inputFile1.txt");

    while(!inputFile.eof()){
        inputFile >> holder;
        depthVector.push_back(holder);
    }

    part1(depthVector);
    part2(depthVector);

    return 0;
}

void part1(vector<int> depthVector) {
    int counter = 0;
    for (int i = 1; i < depthVector.size(); i++) {
        if(depthVector[i-1] < depthVector[i]){
            counter++;
            cout << depthVector[i] << " (Increased) " << endl;
        } else if (depthVector[i-1] > depthVector[i]){
            cout << depthVector[i] << " (Decreased) " << endl;
        } else if (depthVector[i-1] == depthVector[i]){
            cout << depthVector[i] << " (Unchanged) " << endl;
        }
    }
    cout << "Total that are larger than previous: " << counter << endl;
}

void part2(vector<int> depthVector){

}