// sort in increasing order
// Khushi Patel
// 17th decemebr 2023

#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cin; using std::cout; using std::endl;

int main(){
    srand(time(nullptr));
    int randAge = rand() % 100 + 1;
    
    int year = 1000;
    int guessAge;
    bool guess = false;

    cout << "Year " << year << ": Hello, fair maiden. I am a fearsome dragon. How old am I? ";
    cin >> guessAge;

    while(guess != true){
        if(guessAge == randAge){
            cout << "You got it! Here is the handsome prince. Live happily ever after!" << endl;
            guess = true;
        }
        else{
            if(guessAge < randAge){
                randAge += 5;
                cout << "Wrong, I am older. No handsome prince for you. See you in five years." <<endl;
                year += 5;
                cout << "Year " << year << ": Hello, fair maiden. I am a fearsome dragon. How old am I? ";
                cin >> guessAge;
            }
            else{
                randAge += 5;
                cout << "Wrong, I am younger. No handsome prince for you. See you in five years." << endl;
                year += 5;
                cout << "Year " << year << ": Hello, fair maiden. I am a fearsome dragon. How old am I? ";
                cin >> guessAge;
            }
        }
    }
}
