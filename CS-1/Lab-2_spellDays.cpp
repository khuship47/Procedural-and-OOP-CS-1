//print the number in words
//Khushi Patel
//17th december 2023

#include <iostream>
using std::cout; using std::endl; using std::cin;

int main(){

    cout << "Enter any number between 1-35: ";
    int number; cin >> number;

    int doubles = number / 10;
    int singles= number % 10;

    if(number >= 20 && number <= 35) {
        switch(doubles){
            case 2:
                cout << "Twenty ";
                break;
            case 3: 
                cout << "Thirty ";
                break;
            default:
                cout << "Incorrect number" << endl;
        }
        switch(singles){
            case 1:
                cout << "One" << endl;
                break;
            case 2:
                cout << "Two" << endl;
                break;
            case 3:
                cout << "Three" << endl;
                break;
            case 4:
                cout << "Four" << endl;
                break;
            case 5:
                cout << "Five" << endl;
                break;
            default:
                cout << "Incorrect number" << endl;
        }
    }
    if(number >= 10 && number <= 19){
        switch(number){
            case 10:
                cout << "Ten" << endl;
                break;
            case 11:
                cout << "Eleven" << endl;
                break;
            case 12:
                cout << "Twelve" << endl;
                break;
            case 13:
                cout << "Thirteen" << endl;
                break;
            case 14:
                cout << "Fourteen" << endl;
                break;
            case 15:
                cout << "Fifteen" << endl;
                break;
            case 16:
                cout << "Sixteen" << endl;
                break;
            case 17:
                cout << "Seventeen" << endl;
                break;
            case 18:
                cout << "Eighteen" << endl;
                break;
            case 19:
                cout << "Nineteen" << endl;
                break;
            default:
                cout << "Incorrect number" << endl;
        }
    }
    if(number >= 1 && number <= 9){
        switch(singles){
            case 1:
                cout << "One" << endl;
                break;
            case 2:
                cout << "Two" << endl;
                break;
            case 3:
                cout << "Three" << endl;
                break;
            case 4:
                cout << "Four" << endl;
                break;
            case 5:
                cout << "Five" << endl;
                break;
            case 6:
                cout << "Six" << endl;
                break;
            case 7:
                cout << "Seven" << endl;
                break;
            case 8:
                cout << "Eight" << endl;
                break;
            case 9:
                cout << "Nine" << endl;
                break;
            default:
                cout << "Incorrect number" << endl;
        }
    }
    if(number <=1 || number >= 35){
        cout << "Number goes beyond calender limits" << endl;
    }

}