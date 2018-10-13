#include <iostream> 
#include <string>
#include <fstream>
using namespace std;
int matrix[1000][1000];

struct PEAK {
    int row;
    int col;
} peak;

PEAK peak_array[1000000];

int main(int argc, char *argv[]) {
    int row, col;
    int num = 0;
    
    ifstream inFile(argv[1] + string("/matrix.data"), ios::in);
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
            if(i > 0) {
                if(matrix[i][j] < matrix[i - 1][j]) continue;
            } 
            if(i < row - 1) {
                if(matrix[i][j] < matrix[i + 1][j]) continue;
            }
            if(j > 0) {
                if(matrix[i][j] < matrix[i][j - 1]) continue;
            }
            if(j < col - 1) {
                if(matrix[i][j] < matrix[i][j + 1]) continue; 
            }
            peak_array[num].row = i + 1;
            peak_array[num].col = j + 1;
            num++;
        }
    }

    cout << num  << endl;
    for(int i = 0; i < num; i++) {
        cout << peak_array[i].row  << " " << peak_array[i].col << endl;
    }

    return 0;
}