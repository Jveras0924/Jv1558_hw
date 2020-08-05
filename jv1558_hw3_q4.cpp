// Justin Veras - Extended CS Bridge Summer 2020 - Homework 3 - Question 4//

#include <iostream>
using namespace std;

int main()
{
//------------------------------------------------ Constants --------------------------------------------------------//
    const int floor_round = 1;
    const int ceiling_round =2;
    const int round = 3;
//------------------------------------------------ Variables  --------------------------------------------------------//
    int method;

    double real_number, floor_num, difference;
//------------------------------------------------ User Input  --------------------------------------------------------//
    cout << "Please enter a Real number: " << endl;

    cin >> real_number;

    cout << "Choose your rounding method: " << endl;
    cout << "1. Floor round" << endl;
    cout << "2. Ceiling round" << endl;
    cout << "3. Round to the nearest whole number" << endl;
    cin >> method;
//------------------------------------------ Number Rounding  --------------------------------------------------------//
    switch (method) {

        case 1:
            real_number = int(real_number);
            cout << real_number;
            break;
        case 2:
            real_number += 1;
            real_number = int(real_number);
            cout << real_number;
            break;
        case 3:
            floor_num = real_number;
            floor_num = int(floor_num);
            difference = real_number - floor_num;
            if(difference >= .5)
            {
                floor_num += 1;
                cout << floor_num;
            }
            else
                cout << floor_num;
            break;

    }

    return 0;
}

