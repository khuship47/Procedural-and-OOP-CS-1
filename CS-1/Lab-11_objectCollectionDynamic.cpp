//using dynamic object allocation pointers
//Khushi Patel
//26th December 2023

#include <iostream>

using std::cin; using std::cout; using std::endl;

class Collection{
public:
  Collection(): col_(nullptr), size_(0){}; // void constructor
  int size() const {return size_;} // returns the size of the array

  int check(double number){ // returns index of element containg "number" or -1 if none
    for(int i=0; i<size_; ++i){
        if(col_[i] == number){
            return i;
        }
    }
    return -1;
  }

  void addNumber(double number){    // adds number to the collection
    if(check(number) != -1){
        cout << "Duplicate!" << endl;
        return;
    }

    double *newPtr = new double[size_ + 1];
    newPtr[size_] = number;
    
    for(int i=0; i<size_; ++i){
        newPtr[i] = col_[i];
    }
    delete [] col_;
    ++size_;
    col_ = newPtr;
  }

  void removeNumber(double number){ // deletes the number from the collection
    if(check(number) == -1){
        cout << "Not present!" << endl;
        return;
    }

    bool found = false;
    double *newPtr = new double[size_-1];

    for(int i=0; i<size_; ++i){
        if(col_[i] == number)
            found = true;
        else{
            if(!found){
                newPtr[i] = col_[i];
            }
            else{
                newPtr[i - 1] = col_[i];
            }
        }
    }
    delete [] col_;
    --size_;
    col_ = newPtr;
  }
  // do not implement this one 
  void output() const{  // prints the values of the collection
    for(int i=0; i<size_; ++i){
        cout << col_[i] << " ";
    }
    cout << endl;
  }

  // big three
  Collection(const Collection&); // copy constructor
  const Collection& operator=(const Collection&); // overloaded assignment
  ~Collection(); // destructor

private:
  double *col_; // pointer to the dynamically allocated array holding collection of doubles
  int size_;   // array size
};

Collection::~Collection(){
    delete [] col_;
}

Collection::Collection(const Collection& actual){
    size_ = actual.size_;
    col_ = new double[size_]; 

    for(int i=0; i<size_; ++i){
        col_[i] = actual.col_[i];
    }
}

const Collection& Collection::operator=(const Collection& actual){
    if(this != &actual){

        size_ = actual.size_;
        delete [] col_;
        col_ = new double[size_]; 

        for(int i=0; i<size_; ++i){
            col_[i] = actual.col_[i];
        }
    }
    return *this;
}



/*
void testfunc(Collection); // function to test pass-by-value for collection

int main(){

   Collection c1;

   // testing regular member functions
   c1.addNumber(1.);
   c1.addNumber(2.);
   c1.addNumber(3.);
   c1.addNumber(3.); // trying to add duplicate, should not add it
   
   cout << "c1 size is after number addition is: " << c1.size() << endl;
   
   if(c1.check(1.) != -1) // check() returns -1 if number not present
      cout << "1 is present in the array" << endl;

   if(c1.check(5.) != -1)
      cout << "5 is present in the array" << endl;

   cout << "c1 before removal of 2.0: "; c1.output();
   c1.removeNumber(2.);
   cout << "c1 after removal of 2.0: "; c1.output();

   // uncomment this when you debugged the first part
   
   testfunc(c1); // testing copy constructor
   
   cout << "c1 after testfunc call: ";
   c1.output(); // if destructor is implemented correctly
                // this should print properly after testfunc completes

   Collection c2, c3;

   c3=c2=c1; // testing stackability of the overloaded assignment
   cout << "c3 after stackable assingment: ";
   c3.output();

   c3=c3; // testing protection against self-assingment
   cout << "c3 after self-assignment: ";
   c3.output();
   
}

// tests pass-by-value for object of class Collection
void testfunc(Collection c){ // copy constructor is invoked on "c"
    cout << "parameter c: "; 
    c.output(); 
} // destructor is invoked when "c" goes out of scope
*/

int main(){
    Collection doubleCollect;
    int size = 0;
    char ch; double num;
    double *ptr = new double[size];

    do{
        cout << "Charlie, enter operation [a/r/q] and number: ";
        cin >> ch;

        if(ch == 'a'){
            cin >> num;
            doubleCollect.addNumber(num);
            cout << "Your numbers: ";
            doubleCollect.output();
        }
        if(ch == 'r'){
            cin >> num;
            doubleCollect.removeNumber(num);
            cout << "Your numbers: ";
            doubleCollect.output();
        }

    }while(ch != 'q');

}
