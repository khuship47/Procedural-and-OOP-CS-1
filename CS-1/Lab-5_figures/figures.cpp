// Figures with multiple files (function def file)
// Khushi Patel
// 17th decemebr 2023
#include <iostream>
#include "figures.hpp"
using std::cout; using std::endl; using std::cin;

void filledSquare(int size, char ch){
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            cout << ch;
        }
        cout << endl;
    }
}

void hollowSquare(int size, char ch){
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if(row == 0 || col == 0 || row == size-1 || col == size-1)
                cout << ch;
            else
                cout << " ";
        }
        cout << endl;
    }
}

void backslash(int size, char ch){
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if(row == col)
                cout << ch;
            else
                cout << " ";
        }
        cout << endl;
    }
}

void slash(int size, char ch){
    for(int row = 0; row <= size; row++){
        for(int col = 0; col < size; col++){
            if(row + col == size)
                cout << ch;
            else
                cout << " ";
        }
        cout << endl;
    }    
}

void crossedSquare(int size, char ch){
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
}