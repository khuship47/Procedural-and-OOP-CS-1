//line justify
//Khushi Patel
//19th december

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;

const int LineWidth = 80;

int main(){
    srand(time(nullptr));

    cout << "Enter a string: ";
    string str; getline(cin, str);
    cout << "Initial size: " << str.size() << endl; 

    if(str.size() < 40){
        cout << "The end of a paragraph and is not justified." << endl;
    }
    else if(str.size() > 80) {
        cout << "Line is too big to justify." << endl;
    }

    int punctuation = str.find_first_of(",.!?:");

    while(punctuation != string::npos && punctuation != (str.size() - 1) && str.size() < LineWidth){
        str.insert(punctuation+1, "  ");
        punctuation = str.find_first_of(",.!?:", punctuation+1);
    }
 
    while(str.size() < LineWidth){
        int random = rand() % LineWidth;
        punctuation = str.find(' ', random); //after first space start the search from random
    
        if(punctuation != string::npos){
            str.insert(punctuation+1, 1, ' ');
        }
    }

    cout << "The justified line is: " << str << endl;
    cout << "Size: " << str.size();

}