//Patrick Woodworth

//Imports
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


class Board{
    public:
        Board();
        int rowArray[5];
};

Board createBoard();

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
    delimiter = " ";
    int numRow = 0, counter = 0;
    while(getline(inputFile, temp, '\n')){
        cout << temp << endl;
        if(temp.size() == 0){
            numRow = 0;
            continue;
        }
        while((pos=temp.find(delimiter)) != string::npos){
            token = temp.substr(0, pos);
            row[counter] = stoi(token);
            //Breaks on first row of first board.
            //Issue with leading 0s for padding.
            callPool.push_back(stoi(token));
            temp.erase(0, pos + delimiter.length());
            counter++;
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
