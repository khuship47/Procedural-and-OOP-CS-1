//increasing or decreasing depending on user's input
//Khushi Patel
//17th december 2023

#include <iostream>

using std::cout; using std::endl; using std::cin;

int main(){
    cout << "Do you want increasing(i) or decreasing(d) order: ";
    char ch; cin >> ch;

    cout << "Enter three digits for sorting: ";
    int x, y, z; cin >> x >> y >> z;

    if( ch == 'i'){
        if(x > z){
            const int tmp = x;
            x = z;
            z = tmp;
        }
        if(x > y){
            const int tmp = x;
            x = y;
            y = tmp;           
        }
        if(y > z){
            const int tmp = y;
            y = z;
            z = tmp;
        }
        cout << x << " " << y << " " << z << endl;
    }
    else {
        if(x < y){
            const int tmp = x;
            x = y;
            y = tmp;
        }
        if(x < z){
            const int tmp = x;
            x = z;
            z = tmp;
        }
        if(y < z){
            const int tmp = y;
            y = z;
            z = tmp;
        }
        cout << x << " " << y << " " << z << endl;
    }    
}