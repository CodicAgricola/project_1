#include <iostream> 
#include <string>
#include <fstream>
using namespace std;


struct PEAK {
    int row;
    int col;
} peak;

int main(int argc, char *argv[]) {
    int row, col;
    int row_idx = 0;
    int num = 0;
    
    ifstream inFile(argv[1] + string("/matrix.data"), ios::in);
    if(!inFile) {
        cout << "cannot open";
        return 1;
    }

    inFile >> row;
    inFile >> col;
    int matrix[3][col];
    PEAK peak_array[row*col];

    for(int i = 0; i < col; i++) {//load first row
        inFile >> matrix[row_idx][i];
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {//load data of next row
            inFile >> matrix[(row_idx + 1)%3][j];
        }

        for(int j = 0; j < col; j++) {
            if(i > 0) {
                if(matrix[row_idx][j] < matrix[(row_idx + 2)%3][j]) continue;
            } 
            if(i < row - 1) {
                if(matrix[row_idx][j] < matrix[(row_idx + 1)%3][j]) continue;
            }
            if(j > 0) {
                if(matrix[row_idx][j] < matrix[row_idx][j - 1]) continue;
            }
            if(j < col - 1) {
                if(matrix[row_idx][j] < matrix[row_idx][j + 1]) continue; 
            }
            peak_array[num].row = i + 1;
            peak_array[num].col = j + 1;
            num++;
        }

        row_idx = (row_idx + 1)%3;
    }

    cout << num  << endl;
    for(int i = 0; i < num; i++) {
        cout << peak_array[i].row  << " " << peak_array[i].col << endl;
    }

    return 0;
}