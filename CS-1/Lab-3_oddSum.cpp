//add odd numbers
//Khushi Patel
//17th december 2023

#include <iostream>
using std::cout; using std::endl; using std::cin;

int main(){
    int sum = 0;
    int num; 
    do{
        cout << "Input sequence of integers (zero to stop): ";
        cin >> num;
        if(num % 2 != 0){
            sum += num;
        }
    }while( num != 0);
    cout << "The sum of odd numbers is: " << sum << endl;
}
