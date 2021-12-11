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
        cout << "NUM FLASHES SO FAR: " << numFlashes << endl;
        cout << "STEP #: " << j << endl;
        displayBoardState(octoBoard);
        for (int k = 0; k < octoBoard.size(); k++){
            //For # rows
            for (int m = 0; m < octoBoard[k].size(); m++){
                //For # columns
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

vector<vector<int>> updateBoard(vector<vector<int>> octoBoard, int row, int col, int *numFlashes){
    octoBoard[row][col]++;
    if(octoBoard[row][col] >= 9){
        octoBoard[row][col] = 0;
        (*numFlashes)++;
        //CHECK LOCATIONS
        if((row == 0 && col == 0)){
            octoBoard[row][col + 1]++;
            if (octoBoard[row][col + 1] >= 9){
                updateBoard(octoBoard, row, col+1, numFlashes);
            }
            octoBoard[row + 1][col]++;
            if (octoBoard[row + 1][col] >= 9){
                updateBoard(octoBoard, row+1, col, numFlashes);
            }
            octoBoard[row + 1][col + 1]++;
            if (octoBoard[row + 1][col + 1] >= 9){
                updateBoard(octoBoard, row+1, col+1, numFlashes);
            }
        }else if ((row == 0 && col == octoBoard.size())){
            octoBoard[row][col - 1]++;
            if (octoBoard[row][col - 1] >= 9){
                updateBoard(octoBoard, row, col-1, numFlashes);
            }
            octoBoard[row + 1][col - 1]++;
            if (octoBoard[row + 1][col - 1] >= 9){
                updateBoard(octoBoard, row+1, col-1, numFlashes);
            }
            octoBoard[row + 1][col]++;
            if (octoBoard[row + 1][col] >= 9){
                updateBoard(octoBoard, row+1, col, numFlashes);
            }

        }else if ((row == octoBoard[row].size() && col == 0)){
            octoBoard[row - 1][col]++;
            if (octoBoard[row - 1][col] >= 9){
                updateBoard(octoBoard, row-1, col, numFlashes);
            }
            octoBoard[row - 1][col + 1]++;
            if (octoBoard[row - 1][col + 1] >= 9){
                updateBoard(octoBoard, row-1, col+1, numFlashes);
            }
            octoBoard[row][col + 1]++;
            if (octoBoard[row][col + 1] >= 9){
                updateBoard(octoBoard, row, col+1, numFlashes);
            }
        }else if ((row == octoBoard[row].size() && col == octoBoard.size())) {
            octoBoard[row - 1][col - 1]++;
            if (octoBoard[row - 1][col - 1] >= 9){
                updateBoard(octoBoard, row-1, col-1, numFlashes);
            }
            octoBoard[row - 1][col]++;
            if (octoBoard[row - 1][col] >= 9){
                updateBoard(octoBoard, row-1, col, numFlashes);
            }
            octoBoard[row][col - 1]++;
            if (octoBoard[row][col - 1] >= 9){
                updateBoard(octoBoard, row, col-1, numFlashes);
            }
        }else if (row == 0){
            //LEFT AND RIGHT
            octoBoard[row][col - 1]++;
            if (octoBoard[row][col - 1] >= 9){
                updateBoard(octoBoard, row, col-1, numFlashes);
            }
            octoBoard[row][col + 1]++;
            if (octoBoard[row][col + 1] >= 9){
                updateBoard(octoBoard, row, col+1, numFlashes);
            }

            //BELOW
            octoBoard[row + 1][col - 1]++;
            if (octoBoard[row + 1][col - 1] >= 9){
                updateBoard(octoBoard, row+1, col-1, numFlashes);
            }
            octoBoard[row + 1][col]++;
            if (octoBoard[row + 1][col] >= 9){
                updateBoard(octoBoard, row+1, col, numFlashes);
            }
            octoBoard[row + 1][col + 1]++;
            if (octoBoard[row + 1][col + 1] >= 9){
                updateBoard(octoBoard, row+1, col+1, numFlashes);
            }
        }else if (row == octoBoard[row].size()){
            //ABOVE
            octoBoard[row - 1][col - 1]++;
            if (octoBoard[row - 1][col - 1] >= 9){
                updateBoard(octoBoard, row-1, col-1, numFlashes);
            }
            octoBoard[row - 1][col]++;
            if (octoBoard[row - 1][col] >= 9){
                updateBoard(octoBoard, row-1, col, numFlashes);
            }
            octoBoard[row - 1][col + 1]++;
            if (octoBoard[row - 1][col + 1] >= 9){
                updateBoard(octoBoard, row-1, col+1, numFlashes);
            }

            //LEFT AND RIGHT
            octoBoard[row][col - 1]++;
            if (octoBoard[row][col - 1] >= 9){
                updateBoard(octoBoard, row, col-1, numFlashes);
            }
            octoBoard[row][col + 1]++;
            if (octoBoard[row][col + 1] >= 9){
                updateBoard(octoBoard, row, col+1, numFlashes);
            }
        }else if (col == 0){
            //IF ON FIRST COLUMN
            octoBoard[row - 1][col]++;
            if (octoBoard[row - 1][col] >= 9){
                updateBoard(octoBoard, row-1, col, numFlashes);
            }
            octoBoard[row - 1][col + 1]++;
            if (octoBoard[row - 1][col + 1] >= 9){
                updateBoard(octoBoard, row-1, col+1, numFlashes);
            }

            octoBoard[row][col + 1]++;
            if (octoBoard[row][col + 1] >= 9){
                updateBoard(octoBoard, row, col+1, numFlashes);
            }
            octoBoard[row + 1][col]++;
            if (octoBoard[row + 1][col] >= 9){
                updateBoard(octoBoard, row+1, col, numFlashes);
            }
            octoBoard[row + 1][col + 1]++;
            if (octoBoard[row + 1][col + 1] >= 9){
                updateBoard(octoBoard, row+1, col+1, numFlashes);
            }
        }else if (col == octoBoard.size()){
            //IF ON LAST COLUMN
            octoBoard[row - 1][col]++;
            if (octoBoard[row - 1][col] >= 9){
                updateBoard(octoBoard, row-1, col, numFlashes);
            }
            octoBoard[row - 1][col - 1]++;
            if (octoBoard[row - 1][col - 1] >= 9){
                updateBoard(octoBoard, row-1, col-1, numFlashes);
            }
            octoBoard[row][col - 1]++;
            if (octoBoard[row][col - 1] >= 9){
                updateBoard(octoBoard, row, col-1, numFlashes);
            }
            octoBoard[row + 1][col - 1]++;
            if (octoBoard[row + 1][col - 1] >= 9){
                updateBoard(octoBoard, row+1, col-1, numFlashes);
            }
            octoBoard[row + 1][col]++;
            if (octoBoard[row + 1][col] >= 9){
                updateBoard(octoBoard, row+1, col, numFlashes);
            }
        }else{
            //ABOVE
            octoBoard[row - 1][col - 1]++;
            if (octoBoard[row - 1][col - 1] >= 9){
                updateBoard(octoBoard, row-1, col-1, numFlashes);
            }
            octoBoard[row - 1][col]++;
            if (octoBoard[row - 1][col] >= 9){
                updateBoard(octoBoard, row-1, col, numFlashes);
            }
            octoBoard[row - 1][col + 1]++;
            if (octoBoard[row - 1][col + 1] >= 9){
                updateBoard(octoBoard, row-1, col+1, numFlashes);
            }
            

            //LEFT AND RIGHT
            octoBoard[row][col - 1]++;
            if (octoBoard[row][col - 1] >= 9){
                updateBoard(octoBoard, row, col-1, numFlashes);
            }
            octoBoard[row][col + 1]++;
            if (octoBoard[row][col + 1] >= 9){
                updateBoard(octoBoard, row, col+1, numFlashes);
            }

            //BELOW
            octoBoard[row + 1][col - 1]++;
            if (octoBoard[row + 1][col - 1] >= 9){
                updateBoard(octoBoard, row+1, col-1, numFlashes);
            }
            octoBoard[row + 1][col]++;
            if (octoBoard[row + 1][col] >= 9){
                updateBoard(octoBoard, row+1, col, numFlashes);
            }
            octoBoard[row + 1][col + 1]++;
            if (octoBoard[row + 1][col + 1] >= 9){
                updateBoard(octoBoard, row+1, col+1, numFlashes);
            }
        }
        }
    cout << endl << *numFlashes << endl; 
    displayBoardState(octoBoard);
    return octoBoard;
}