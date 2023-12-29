// sort in increasing order using function
// Khushi Patel
// 18th decemebr 2023

#include <iostream>

using std::cin; using std::cout; using std::endl;

void swap(int&, int&);

int main(){

    cout << "Enter three numbers: ";
    int x, y, z;
    cin >> x >> y >> z;

    if(x > y){
        swap(x, y);
    }
    if(x > z){
        swap(x, z);
    }
    if(y > z){
        swap(y, z);
    }

    cout << "The sorted numbers are: ";
    cout << x << " " << y << " " << z << endl;
}

void swap(int& left, int& right) {
    const int tmp = left;
    left = right;
    right = tmp;
}