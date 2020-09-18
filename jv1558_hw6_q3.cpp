//  This program gives an approximation of the mathematical value of e based on the infinite formula e = 1 + 1/1! + ...
//  Input from user: Enter the length of the of the partial sum of e to get an approximation
//  Output to user: The program first outputs the the first 15 approximations then outs puts your inputed approximation
/*
#include <iostream>
using namespace std;
//---------------------------------------- Functions -----------------------------------------------------------------//
double factorial(int num);

double eApprox(int n);
//---------------------------------------- Main body of Program ------------------------------------------------------//
int main(){
//-------------------------------- Variables -------------------------------------------------------------------------//
    int n;
//----------------------------------- Length of digits past decimal point --------------------------------------------//
    cout.precision(30);
//---------------------------------------- Approximation 1 - 15 ------------------------------------------------------//
    for (int n = 1; n <= 15; n++) {
        cout<<"n = "<< n << '\t' <<eApprox(n) <<endl; }
//---------------------------------------- User input Approximation --------------------------------------------------//
    cout << "Please enter a positive integer: ";
    cin >> n;
    cout << "n = " << n << '\t' << eApprox(n);
    return 0;
}
//---------------------------------------- Factorial Function --------------------------------------------------------//
double factorial(int num){
    double factRes, i;

    factRes = 1;
    for(i = 1; i <= num; i += 1){
        factRes *= i;
    }
    return factRes;
}
//---------------------------------------- e Approximation Function --------------------------------------------------//
double eApprox(int n){
    const double one = 1;
    double e = 1, addE, count = 1;

    while(count <= n){
        addE = one / factorial(count);
        e += addE;
        count += 1;
    }
    return e;

}
*/