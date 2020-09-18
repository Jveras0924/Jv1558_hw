//   This program allows the user to create a pine tree
//   Input from user: Positive integer that denotes number of triangle in the tree
//   Output to user: Pine tree
/*
#include <iostream>
using namespace std;
//---------------------------------------- Functions -----------------------------------------------------------------//
void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);
//---------------------------------------- Main body of Program ------------------------------------------------------//
int main() {
//-------------------------------- Variables -------------------------------------------------------------------------//
    int n;
    char symbol;
//-------------------------------- User Input ------------------------------------------------------------------------//
    cout << "Please enter a positive integer: " << endl;
    cin >> n;

    cout << "Please enter one of these characters *, +, or $. Only enter one: )" << endl;
    cin >> symbol;
//-------------------------------- Tree Creation ---------------------------------------------------------------------//
    printPineTree(n, symbol);


    return 0;
}
//-------------------------------- Shifted Triangle Function  --------------------------------------------------------//
void printShiftedTriangle(int n, int m, char symbol){

    int col, len, row, shift;
    len = (2 * n) - 1;

    for( col = 1; col <= n; col += 1){
        for (shift = 1; shift <= m; shift += 1)
            cout << " ";
        for(row = 1; row <= len; row += 1) {
            if (row >= n - (col - 1) && row <= n + (col - 1)){
                cout << symbol;
            }
            else
                cout << " ";
        }
        cout << endl;
    }
}
//-------------------------------- Pine Tree Function  ---------------------------------------------------------------//
void printPineTree(int n, char symbol){

    int m, temp;

    temp = n;

    for (n = 2, m = temp; n <= (temp + 1); n += 1, m -= 1) {
        printShiftedTriangle(n, m, symbol);
    }
}
*/