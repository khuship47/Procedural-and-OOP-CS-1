// sort in increasing order
// Khushi Patel
// 17th decemebr 2023

#include <iostream>

using std::cin; using std::cout; using std::endl;

int main(){

  // inputs the numbers
  cout << "Enter three numbers: ";
  int x, y, z;
  cin >> x >> y >> z;

  // orders x and y
  if (x > y){
    if(x > z){
        const int tmp = x;
        x = z;
        z = tmp;
    }
    else{
        const int tmp = x;
        x = y;
        y = tmp;
    }
  }

  // orders y and z
  if (y > z){
    const int tmp = y;
    y = z;
    z = tmp;
  }
  if(x > y){
    const int tmp = y;
    y = x;
    x = tmp;
  }

  // outputs the sorted numbers
  cout << "The sorted numbers are: ";
  cout << x << " " << y << " " << z << endl;
}