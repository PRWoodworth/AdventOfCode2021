//Patrick Woodworth

//Imports
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <regex>

using namespace std;


class Board{
    public:
        Board();
        int rowArray[5];
        void setRow(int[], int);
};

Board::Board(){};
void Board::setRow(int row[], int numRow){
    this->rowArray[numRow] = *row;
};


int main(int argc, char const *argv[]){
    ifstream inputFile;
    /*
    up to 5+(n-1) (where n = number of rounds played) numbers drawn per round. If less numbers remain, call all remaining (at end of call pool)
    i.e: 5 on round 1, 6 on round 2, 7 on round 3, etc.

    Score of winning board:
    sum of all unmarked numbers * number that was called last that caused the board to win 
    */
    string temp = "";
    string delimiter = ",";
    string token;
    int pos = 0;
    vector<int> callPool;
    vector<Board> boardsVector;
    int row[5];
    inputFile.open("inputFile.txt");

    //read first line in
    getline(inputFile, temp);
    temp += delimiter;
    //parse first line
    while((pos=temp.find(delimiter)) != string::npos){
        token = temp.substr(0, pos);
        callPool.push_back(stoi(temp));
        temp.erase(0, pos + delimiter.length());
    }
    //until end of file
    //read in board
    //create board
    Board newBoard;
    delimiter = " ";
    int numRow = 0, counter = 0;
    while(getline(inputFile, temp, '\n')){
        if(temp.size() == 0){
            numRow = 0;
            continue;
        }
        while((pos=temp.find(delimiter)) != string::npos){
            if(temp[0] == ' '){
                temp.erase(0, 1);
                pos++;
            }
            cout << temp << endl;
            token = temp.substr(0, pos);
            token = regex_replace(token, regex("^ +"), "");
            token = regex_replace(token, regex(" +$"), "");
            cout << token << endl;
            row[counter] = stoi(token);
            temp.erase(0, pos + delimiter.length());
            counter++;
        }
        //Add newly created row to a Board object here
        newBoard.setRow(row, numRow);
        cout << endl;
        if(numRow == 5){
            boardsVector.push_back(newBoard);
        }
        numRow++;
    }

    //for each number in callPool
    //for each board
    //for each row
    //for each column
    //if callPool number == board[x][y]
    //board[x][y] = -1

    inputFile.close();

    return 0;
}
