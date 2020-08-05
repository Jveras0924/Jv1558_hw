// Justin Veras - Extended CS Bridge Summer 2020 - Homework 3 - Question 3//

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
//---------------------------------------------- Variable -----------------------------------------------------------//
    double a, b, c, x, discriminant, square_root, negative_b, two_a, x_1, x_2;
//---------------------------------------------- User Input ----------------------------------------------------------//
    cout << "Please enter value of a: ";
    cin >> a;

    cout << "Please enter value of b: ";
    cin >> b;

    cout << "Please enter value of c: ";
    cin >> c;
//------------------------------------ Discriminant Calculation ------------------------------------------------------//
    discriminant = (b * b ) - (4 * a * c);
    negative_b = b * (-1);
    two_a = (a * 2);
//------------------------------------ Square Root of Discriminant  --------------------------------------------------//
    square_root = sqrt(discriminant);
//---------------------------------------------- Solutions  -----------------------------------------------------------//
    if(a =! 0)

        if(discriminant == 0){
            x = (negative_b) / (two_a);
            cout << "The equation has a single real solution x = " << x;
        }
        else if(discriminant > 0){
            x_1 = (negative_b + (square_root)) / two_a;
            x_2 = (negative_b - (square_root)) / two_a;
            cout << "The equation has two real solutions x = " << x_1 << " and x = " << x_2;
        }
        else if(discriminant < 0){
            cout << "The equation has no real solution";
        }
    else if(a == 0 && b == 0 && c == 0)
        cout << "The equation has an infinite number of solutions";
    else if ( a == 0 && b == 0 && c > 0 && c < 0)
        cout << "The equation has no solution";


    return 0;




}

