//Patrick Woodworth

//Imports
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void rawPart();
void aimPart();

int main(int argc, char const *argv[]){
    rawPart();
    aimPart();
    
    return 0;
}

void rawPart(){
    int depth = 0;
    int h_pos = 0;
    int distance;
    ifstream inputFile;

    inputFile.open("inputFile.txt");
    string direction;
    while(inputFile >> direction >> distance){
        // inputFile >> direction >> distance;
        // cout << direction << " " << distance << endl;
        if(direction == "forward"){
            h_pos += distance;
        }else if(direction == "up"){
            depth -= distance;
        }else if(direction == "down"){
            depth += distance;
        }
        distance = 0;
    }
    cout << "Part 1 Horizontal Position * Depth = " << h_pos * depth << endl;
    inputFile.close();
}

void aimPart(){
    int depth = 0;
    int h_pos = 0;
    int aim = 0;
    int distance = 0;
    ifstream inputFile;

    inputFile.open("inputFile.txt");
    string direction;
    while(inputFile >> direction >> distance){
        // inputFile >> direction >> distance;
        // cout << direction << " " << distance << endl;
        if(direction == "forward"){
            h_pos += distance;
            depth += (aim*distance);
        }else if(direction == "up"){
            aim -= distance;
        }else if(direction == "down"){
            aim += distance;
        }
        distance = 0;
    }
    cout << "Part 2 Horizontal Position * Depth = " << h_pos * depth << endl;
    inputFile.close();
}