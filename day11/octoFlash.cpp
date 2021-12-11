#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

static const int NUM_STEPS = 100;

int main(int argc, char const *argv[]){

    vector<vector<int>> octoBoard(10);
    int numFlashes = 0;
    int row = 0;
    string temp = "";
    string token;
    ifstream inputFile;
    inputFile.open("inputFile.txt");

    while(getline(inputFile, temp, '\n')){
        for (int i = 0; i < temp.size(); i++){
            octoBoard[row].push_back(int(temp[i]-'0'));
        }
        row++;
    }
    for (int j = 0; j < NUM_STEPS; j++){
        for (int k = 0; k < octoBoard.size(); k++){
            //For # rows
            for (int m = 0; m < octoBoard[row].size(); m++){
                //For # columns
                //increment all nodes
                octoBoard[k][m]++;
                //flash
                if(octoBoard[k][m] >= 9){
                    octoBoard[k][m] = 0;
                    //increment adjacents
                }   
            }
        }
    }
    inputFile.close();
    return 0;
}