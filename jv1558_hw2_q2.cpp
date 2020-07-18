// Justin Veras - Extended CS Bridge Summer 2020 - Homework 2 - Question 2//

#include <iostream>
using namespace  std;

int main()
{
    //-------------------------------------------------- Variables -------------------------------------------------//
    int dollarAmount, changeAmount, totalMoney, quarters, dimes, nickels, pennies;
//-------------------------------------------- Data gathering from user --------------------------------------------//
    cout << "Please enter your amount in the format of dollars and cents seperated by a space: " << endl;

    cin >> dollarAmount >> changeAmount;
//------------------------------------------- Repeating Data to the User ---------------------------------------//
    cout << dollarAmount << " dollars and " << changeAmount << " cents are: " << endl;
//------------------------------------------ Converting dollars to cents ---------------------------------------//
    dollarAmount = dollarAmount * 100;

    totalMoney = dollarAmount + changeAmount;
//----------------------------------------- Converting cents to quarters ---------------------------------------//
    quarters = totalMoney / 25;

    totalMoney = totalMoney % 25;
//----------------------------------------- Converting leftover cents to dimes ----------------------------------//
    dimes = totalMoney / 10;

    totalMoney = totalMoney % 10;
//----------------------------------------- Converting leftover cents to nickels ----------------------------------//
    nickels = totalMoney / 5;

    totalMoney = totalMoney % 5;
//----------------------------------------- Converting leftover cents to pennies ----------------------------------//
    pennies = totalMoney / 1;
//----------------------------------------- Stating converted currency --------- ----------------------------------//
    cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, and  " << pennies << " pennies" <<
    endl;

    return 0;

}

