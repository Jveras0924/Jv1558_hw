// Justin Veras - Extended CS Bridge Summer 2020 - Homework 2 - Question 1//

#include <iostream>
using namespace std;

int main()
{
    //----------------------------------------- Variables -------------------------------------------------------//
    int totalQuarters, totalDimes, totalNickles, totalPennies, totalChange, totalDollars, spareChange;
//----------------------------------------- Data Gathering From User---------- ----------------------------------//
    cout << "Please enter number of coins: " << endl;

    cout << "# of quarters: ";
    cin >> totalQuarters;

    cout << "# of dimes: ";
    cin >> totalDimes;

    cout << "# of nickles: ";
    cin >> totalNickles;

    cout << "# of pennies: ";
    cin >> totalPennies;
//----------------------------------------- Converting change to cents ------ ----------------------------------//
    totalQuarters = totalQuarters * 25;

    totalDimes = totalDimes * 10;

    totalNickles = totalNickles * 5;

    totalPennies = totalPennies * 1;
//----------------------------------------- Adding converted change together - ----------------------------------//
    totalChange = totalQuarters + totalDimes + totalNickles + totalPennies;
//----------------------------------------- Converting added changed to dollars ----------------------------------//
    totalDollars = totalChange / 100;
//----------------------------------------- Showing spare change ------------- ----------------------------------//
    spareChange = totalChange % 100;
//----------------------------------------- Outputing converted change into dollars  -----------------------------//
    cout << "The total is " << totalDollars << " dollars and " << spareChange << " cents" << endl;

    return 0;
}

