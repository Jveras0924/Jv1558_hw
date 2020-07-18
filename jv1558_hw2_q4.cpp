// Justin Veras - Extended CS Bridge Summer 2020 - Homework 2 - Question 4//

#include <iostream>
using namespace std;

int main()
{
//---------------------------------- Variables ----------------------------------------------------------------------//
    int positveInterger1, postiveInterger2, sum, difference, product, div, mod;
    double divison;
//---------------------------------------- Interger Data from User ------------------------------------------------//
    cout << "Please enter two positve intergers, seperated by a space: " << endl;
    cin >> positveInterger1 >> postiveInterger2;
//------------------------------------------ Adding the Two Intergers --------------------------------------------//
    sum = positveInterger1 + postiveInterger2;

    cout << positveInterger1 << " + " << postiveInterger2 << " = " << sum << endl;
//--------------------------------------- Subtracting the Two Intergers --------------------------------------------//
    difference = positveInterger1 - postiveInterger2;

    cout << positveInterger1 << " - " << postiveInterger2 << " = " << difference << endl;
//--------------------------------------- Multipling the Two Intergers --------------------------------------------//
    product = positveInterger1 * postiveInterger2;

    cout << positveInterger1 << " * " << postiveInterger2 << " = " << product << endl;
//--------------------------------------- Double Division on the Two Intergers ---------------------------------------//
    divison = (double) positveInterger1 / (double) postiveInterger2;

    cout << positveInterger1 << " / " << postiveInterger2 << " = " << divison << endl;
//--------------------------------------- Int divison on the Two Intergers -------------------------------------------//
    div = positveInterger1 / postiveInterger2;

    cout << positveInterger1 << " div " << postiveInterger2 << " = " << div << endl;
//--------------------------------------- Modulus of the Two Intergers --------------------------------------------//
    mod = positveInterger1 % postiveInterger2;

    cout << positveInterger1 << " mod " << postiveInterger2 << " = " << mod << endl;


    return 0;
}
