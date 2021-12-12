#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

static int NUM_STEPS = 100;
static int START_FLASHES = 0;

void displayBoardState(vector<vector<int>>);
vector<vector<int>> updateBoard(vector<vector<int>>, int, int, int*);

int main(int argc, char const *argv[]){

    vector<vector<int>> octoBoard(10);
    int *numFlashes;
    numFlashes = &START_FLASHES;
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
        cout << "NUM FLASHES SO FAR: " << *numFlashes << endl;
        cout << "STEP #: " << j << endl;
        displayBoardState(octoBoard);
        for (int k = 0; k < octoBoard.size(); k++){
            //For # columns
            for (int m = 0; m < octoBoard[k].size(); m++){
                //For # rows
                //increment all nodes
                octoBoard = updateBoard(octoBoard, k, m, numFlashes);
            }
        }
    }
    inputFile.close();
    return 0;
}

void displayBoardState(vector<vector<int>> octoBoard){
    for (int k = 0; k < octoBoard.size(); k++){
        for (int m = 0; m < octoBoard[k].size(); m++){
            cout << octoBoard[k][m];
        }
        cout << endl;
    }
    cout << endl;
}
//Struct to define all possible adjacencies
struct {
    int dx;
    int dy;
} directions[] = {{-1,-1,},{-1,0,},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

vector<vector<int>> updateBoard(vector<vector<int>> octoBoard, int row, int col, int *numFlashes){
    
    octoBoard[row][col]++;
    if(octoBoard[row][col] >= 9){
        octoBoard[row][col] = 0;
        (*numFlashes)++;
        //for every possible adjacent direction
        for (int i = 0; i < sizeof(directions); i++){
            //if it's within bounds
            if((0 <= row + directions[i].dx <= 10) && ( 0 <= col + directions[i].dy <= 10)){
                //increment it on flash as well
                octoBoard[row + directions[i].dx][col + directions[i].dy]++;
                //if that increment causes it to go over 9
                if (octoBoard[row + directions[i].dx][col + directions[i].dy] >= 9){
                    //recursively call centered on that index
                    octoBoard = updateBoard(octoBoard, row + directions[i].dx, col + directions[i].dy, numFlashes);
                }
            }
        }
    }
    return octoBoard;
}