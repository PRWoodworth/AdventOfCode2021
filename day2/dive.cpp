//Patrick Woodworth

//Imports
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
    int depth = 0;
    int h_pos = 0;
    int distance;

    string temp;
    string direction;

    vector<string> directionVector;
    vector<int> distanceVector;

    ifstream inputFile;

    inputFile.open("inputFile.txt");
    while(getline(inputFile, temp)){
        //TODO: split temp into direction and distance using space as delimiter
    }
}
