//       This program allows the user to search for a number in the Fibonacci sequence, using that numbers place
//       in the sequence
//       Input from user: Place in Fibonacci sequence
//       Output to user: Fibonacci number in the place inputed
/*
#include <iostream>
using namespace std;
//---------------------------------------- Functions -----------------------------------------------------------------//
int fib(int n);
//---------------------------------------- Main body of Program ------------------------------------------------------//
int main(){
//-------------------------------- Variables -------------------------------------------------------------------------//
    int num, nTh_Fib;
//-------------------------------- User Input ------------------------------------------------------------------------//
    cout << "Please enter a positive integer: ";
    cin >> num;
//-------------------------------- Fibonacci Calculation -------------------------------------------------------------//
    nTh_Fib = fib(num);
//-------------------------------- Fibonacci Output  -----------------------------------------------------------------//
    cout << nTh_Fib;

    return 0;
}
//-------------------------------- Fibonacci Calculation Function  ---------------------------------------------------//
int fib(int n){

    int f0, f1, fN, count;

    f0 = 0;
    f1 = 1;
    fN = 0;

    for(count = 1; count <= (n - 1); count += 1){
        fN = f0 + f1;
        f0 = f1;
        f1 = fN;
    }
    return fN;
}
*/