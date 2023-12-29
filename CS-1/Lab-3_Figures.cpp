// Draw the figures
//Khushi Patel
//17th December 2023

#include <iostream>
using std::cout; using std::endl; using std::cin;

int main(){
    cout << "Input figure size: ";
    int size; cin >> size;

    cout << "Input paint character: ";
    char ch; cin >> ch;

    //filled square
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            cout << ch;
        }
        cout << endl;
    }
    cout << endl;

    //hollow square
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if(row == 0 || col == 0 || row == size-1 || col == size-1)
                cout << ch;
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    //backward slash
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if(row == col)
                cout << ch;
            else
                cout << " ";
        }
        cout << endl;
    }

    //forward slash
    for(int row = 0; row <= size; row++){
        for(int col = 0; col < size; col++){
            if(row + col == size)
                cout << ch;
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    //crossed square
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if(row == 0 || col == 0 || row == size-1 || 
            col == size-1 || row + col == size-1 || row == col)
                cout << ch;
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;

}

