// Figures with multiple files (Main file)
// Khushi Patel
// 17th decemebr 2023
#include <iostream>
#include "figures.hpp"
using std::cout; using std::endl; using std::cin;

int main(){
    int size;  char ch;  int fig;

    do{
        cout << "select size: ";
        cin >> size;

        cout << "select paint character ";
        cin >> ch;

        cout << "1. square \n2. slash \n3. crossed square" << endl;
        cout << "select figure: ";
        cin >> fig;

        switch(fig){
            case 1:
                cout << "filled, hollow [f/h]: ";
                char s; cin >> s;
                if(s == 'f'){
                    filledSquare(size, ch);
                    cout << endl;
                }
                else if(s == 'h'){
                    hollowSquare(size, ch);
                    cout << endl;
                }
                else{
                    cout << "Invalid input!";
                }
                break;

            case 2:
                cout << "forward, backward [f/b]: ";
                char sl; cin >> sl;
                if(sl == 'f'){
                    slash(size, ch);
                    cout << endl;
                }
                else if(sl == 'b'){
                    backslash(size, ch);
                    cout << endl;
                }
                else{
                    cout << "Invalid input!";
                }
                break;
            
            case 3:
                crossedSquare(size, ch);
                cout << endl;
                break;

            default:
                cout << "Invalid figure!" << endl;
        }
    }while(fig == 1 || fig == 2 || fig == 3);
}