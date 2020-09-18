//  This program allows the user to input an integer, then the program outputs that integer's divisors
//  Input from the user: Positive integer greater than or equal to two
//  Output to user: List of divisors of that integer in ascending order

#include <iostream>
#include <cmath>
using namespace std;
//---------------------------------------- Functions -----------------------------------------------------------------//
void printDivisors(int num);
//---------------------------------------- Main body of Program ------------------------------------------------------//
int main(){
//-------------------------------- Variables -------------------------------------------------------------------------//
    int num;
//-------------------------------- User Input ------------------------------------------------------------------------//
    cout << "Please enter a positive integer >= 2: ";
    cin >> num;
//-------------------------------- Print Divisors --------------------------------------------------------------------//
    printDivisors(num);
    return 0;
}
//-------------------------------- Divisor Function ------------------------------------------------------------------//
void printDivisors(int num) {

    int divisor, divisor2, temp;

    divisor2 = 1;

    for (divisor = 1; divisor < sqrt(num); divisor += 1, divisor2 += 1) {
        if (num % divisor == 0)
            cout << " " << divisor << " ";
    }
    for (divisor = divisor + 1; divisor != 0; divisor -= 1, divisor2 -= 1) {
        temp = divisor2;
        if (num % divisor == 0)
            divisor2 = num / divisor;
        if (num % divisor2 == 0)
            if(divisor2 != temp)
                cout << " " << divisor2 << " ";
    }

}
