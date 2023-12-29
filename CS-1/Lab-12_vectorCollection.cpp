//using vectors
//Khushi Patel
//26th December 2023

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::vector;

void output(vector<double>&);
void addNumber(vector<double>&, double);
void removeNumber(vector<double>&, double);

int main(){
    vector<double> vec;
    char ch; double num;

    do{
        cout << "Charlie, enter operation [a/r/q] and number: ";
        cin >> ch;

        if(ch == 'a'){
            cin >> num;
            addNumber(vec,num);
            cout << "Your numbers: ";
            output(vec);
        }
        if(ch == 'r'){
            cin >> num;
            removeNumber(vec,num);
            cout << "Your numbers: ";
            output(vec);
        }

    }while(ch != 'q');
}

void output(vector<double>& vec){
    
    for(std::vector<double>::iterator it = vec.begin(); it != vec.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

void addNumber(vector<double>& vec, double number){
    if(vec.empty()){
        vec.push_back(number);
    }
    else{
        std::vector<double>::iterator it;
        it = find(vec.begin(), vec.end(), number);
        if(it == vec.end()){
            vec.push_back(number);
        }
        else{
            cout << "Duplicate" << endl;
        }
    }
}

void removeNumber(vector<double>& vec, double number){
    std::vector<double>::iterator it;
    it = find(vec.begin(), vec.end(), number);
    
    if(it != vec.end()){
        vec.erase(it);
    }
    else{
        cout << "Not present!" << endl;
    }
}