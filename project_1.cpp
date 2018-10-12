#include <iostream> 
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    cout<<"argc = "<<argc<<endl;
    cout<<"argv : ";
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << " ";
    }
    cout<<endl;
    ifstream inFile(argv[1], ios::in);
    if(!inFile) {
        cout << "cannot open";
        return 1;
    }
    int x;
    
    while(!inFile.eof()) {
        inFile >> x;
        cout << x << endl;
    }

    return 0;
}