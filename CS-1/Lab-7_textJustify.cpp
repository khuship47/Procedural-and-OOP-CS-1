//Text justify
//Khushi Patel
//19th december

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

using std::cin; using std::cout; using std::endl;
using std::ifstream; using std::ofstream;
using std::string;

const int line_width = 80;

int main(){
    srand(time(nullptr));

    ifstream input("unjustified.txt");
    ofstream output("justified.txt");
    if(!input) cout << "unable to open the file";
    if(!output) cout << "unable to open the file";

    string str;
    while(getline(input, str)){
        if(str.size() > 80) {
            cout << "Line is too big to justify." << endl;
        }

        int punctuation = str.find_first_of(",.!?:");
        output << "str: " << str[punctuation+1];


        while(punctuation != string::npos && punctuation != (str.size() - 1) && str.size() < line_width){
           
                str.insert(punctuation+1, "  ");
                punctuation = str.find_first_of(",.!?:", punctuation+1);
            
        }
 /*
        while(str.size() < line_width){
            int random = rand() % line_width;
            punctuation = str.find(' ', random); //after first space start the search from random
        
            if(punctuation != string::npos){
                str.insert(punctuation+1, 1, ' ');
            }
        }
        output << str << endl;
        */
    }
    
}