#include <iostream> 
#include <fstream>
using namespace std;
int matrix[1000][1000];

int main(int argc, char *argv[]) {
    int row, col;
    
    ifstream inFile(argv[1], ios::in);
    if(!inFile) {
        cout << "cannot open";
        return 1;
    }

    inFile >> row;
    inFile >> col;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            inFile >> matrix[i][j];
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}