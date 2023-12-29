//using pointers
//Khushi Patel
//26th December 2023

#include <iostream>

using std::cin; using std::cout; using std::endl;

// prints the values in array "colPtr" of "size" 
void output(const double *colPtr, const int size){
    for(int i=0; i<size; ++i){
        cout << colPtr[i] << " ";
    }
    cout << endl;
}

// returns the sum of all the values in array "colPtr" of "size"
// do not implement this one
double value(const double *colPtr, const int size){
    int sum=0;
    for(int i=0; i<size; ++i){
        sum += colPtr[i];
    }
    return sum;
}

// returns the index of the element in array "colPtr" of "size"
// that corresponds to the element holding "number"
// if number is not in the array, returns -1
int check(const double *colPtr, const double number, const int size){
    for(int i=0; i<size; ++i){
        if(colPtr[i] == number){
            return i;
        }
    }
    return -1;
}

// adds "number" to the array pointed to by "colPtr" of "size". 
// if the number is not already there, if "number" is there - no action
// Note, the size of the array is thus increased. 
void addNumber(double *& colPtr, const double number, int &size){
    if(check(colPtr,number,size) != -1){
        cout << "Duplicate!" << endl;
        return;
    }

    double *newPtr = new double[size + 1];
    newPtr[size] = number;
    
    for(int i=0; i<size; ++i){
        newPtr[i] = colPtr[i];
    }
    delete [] colPtr;
    ++size;
    colPtr = newPtr;
    
}

// removes a "number" from array "colPtr" of "size".
// if "number" is not there -- no action
// note, "size" changes
void removeNumber(double *& colPtr, const double number, int &size){
    if(check(colPtr,number,size) == -1){
        cout << "Not present!" << endl;
        return;
    }

    bool found = false;
    double *newPtr = new double[size-1];

    for(int i=0; i<size; ++i){
        if(colPtr[i] == number)
            found = true;
        else{
            if(!found){
                newPtr[i] = colPtr[i];
            }
            else{
                newPtr[i - 1] = colPtr[i];
            }
        }
    }
    delete [] colPtr;
    --size;
    colPtr = newPtr;
}

/*
int main(){

   int size=5;  // setting collection array size
   double *a = new double[size]; // allocating dynamic array

   // collection initializing array
   a[0] = 0.; a[1] = 10.; a[2] = 20.; a[3] = 30.; a[4] = 40.;

   cout << "Collection: ";
   output(a, size); // printing out the array
   
   
   // asking user to input a number
   cout << "Input number to find in Charlie's collection: ";
   double number;
   cin >> number;

   // checking if the input number is in the collection 
   int index = check(a, number, size);
   if (index == -1)
      cout << "The number is not Charlie's collection" << endl;
   else
      cout << "The number is at position " << index << endl;

   
   
   // adding a new number to the collection
   addNumber(a, 55.5, size);
   cout << "Charlie's collection after adding a new number: "; output(a, size);

   // adding a duplicate number to collection
   // the function should not add it
   addNumber(a, 20., size);
   cout << "Charlie's collection after adding existing number: "; output(a, size);

   // 
   removeNumber(a, 10., size);
   cout << "Charlie's collection after removing a number: "; output(a, size);


   delete [] a; // deallocating the array
   
}
*/

int main(){
    int size = 0;
    char ch; double num;
    double *ptr = new double[size];

    do{
        cout << "Charlie, enter operation [a/r/q] and number: ";
        cin >> ch;

        if(ch == 'a'){
            cin >> num;
            addNumber(ptr,num,size);
            cout << "Your numbers: ";
            output(ptr,size);
        }
        if(ch == 'r'){
            cin >> num;
            removeNumber(ptr,num,size);
            cout << "Your numbers: ";
            output(ptr,size);
        }

    }while(ch != 'q');

    int total = value(ptr, size);
    cout << "Total: " << total << endl;
}
