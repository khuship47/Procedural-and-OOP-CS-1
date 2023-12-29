// sort in increasing order using function
// Khushi Patel
// 18th decemebr 2023

#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cin; using std::cout; using std::endl;


void assign(int []);
bool check(int, int[]);
void draw(int []);
int entry();
void printOut(int []);


const int total_lottery_num = 10;
const int total_user_num = 5;

int main(){
    srand(time(nullptr));

    int input_num;    
    int lottery_array[total_lottery_num];

    assign(lottery_array);
    draw(lottery_array);

    for(int i=0; i<total_user_num; ++i){
        input_num = entry();
        if(check(input_num, lottery_array)){
            cout << "You won!" << endl;
            break;
        }
    }
    if(!check(input_num, lottery_array)){
        cout << "You Lost!" << endl;
    }

    printOut(lottery_array);
}

void assign(int chosen[]){
    for(int i=0; i < total_lottery_num; ++i){
        chosen[i] = -1;
    }
}

bool check(int number, int chosen[]){
    for(int i=0; i < total_lottery_num; ++i){
        if(chosen[i] == number){
            return true;
        }
    }
    return false;
}

void draw(int chosen[]){
    int num_of_select_lot_num = 0;
    while(num_of_select_lot_num < total_lottery_num){
        int random = rand() % 100;
        if(!check(random, chosen)){
            chosen[num_of_select_lot_num ] = random;
            ++num_of_select_lot_num;
        }
    }
}

int entry(){
    cout << "Enter a number between[0-99]: ";
    int num; cin >> num;
    return num;
}

void printOut(int chosen[]){
    cout << "Selected lottery number: ";
    for(int i=0; i<total_lottery_num; ++i){
        cout << chosen[i] << " ";
    }
    cout << endl;
}