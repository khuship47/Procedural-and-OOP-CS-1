// Basal Metabolic Rate for men and women
// Khushi Patel
// 17th decemebr 2023

#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cin; using std::cout; using std::endl;


double bmrWomen(double, double, int);
double bmrMen(double, double, int);

int main(){
    cout << "Enter your gender [women(w) / men(m)]: ";
    char ch; cin >> ch;

    if(ch == 'W' || ch == 'w'){
        cout << "Enter your weight in pounds: ";
        double w; cin >> w;
        cout << "Enter your height in feet and inches (5.8): ";
        double h; cin >> h;
        h = h * 12;
        cout << "Enter your age in years: ";
        int a; cin >> a;
        double womenBMR = bmrWomen(w, h, a);
        int numOfCookies = womenBMR / 142;
        cout << "Women Basal Metabolic Rate is: " << womenBMR << " and can eat "<< numOfCookies << " per day." << endl;
    }
    else{
        cout << "Enter your weight in pounds: ";
        double w; cin >> w;
        cout << "Enter your height in feet and inches (5.8): ";
        double h; cin >> h;
        h = h * 12;
        cout << "Enter your age in years: ";
        int a; cin >> a;
        double menBMR = bmrMen(w, h, a);  
        int numOfCookies = menBMR / 142; 
        cout << "Women Basal Metabolic Rate is: " << menBMR << " and can eat "<< numOfCookies << " per day." << endl;    
    }
    
}

double bmrWomen(double w, double h, int a){
    double bmrW =   655 + (4.3 * w) + (4.7 * h) - (4.7 * a);
    return bmrW;
}

double bmrMen(double w, double h, int a){
    double bmrM =  66 + (6.3 * w) + (12.9 * h) - (6.8 * a);
    return bmrM;
}