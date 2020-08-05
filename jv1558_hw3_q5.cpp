// Justin Veras - Extended CS Bridge Summer 2020 - Homework 3 - Question 5//

#include <iostream>
using namespace std;

int main()
{
//----------------------------------------- Constants ---------------------------------------------------------------//
    const double kilo = .453592;
    const double meter =.0254;
//----------------------------------------- Variables  ---------------------------------------------------------------//
    double weightPounds, heightInches, weightKilo, heightMeters, heightSquare, bodyMassIndex;
//----------------------------------------- User Input  ---------------------------------------------------------------//
    cout << "Please enter weight (in pounds): ";

    cin >> weightPounds;

    cout << "Please enter height (in inches): ";

    cin >> heightInches;
//----------------------------------------- BMI Calculations  --------------------------------------------------------//
    weightKilo = weightPounds * kilo;

    heightMeters = heightInches * meter;

    heightSquare = heightMeters * heightMeters;

    bodyMassIndex = weightKilo / heightSquare;
//----------------------------------------- BMI Output---------------------------------------------------------------//
    if(bodyMassIndex < 18.5)
        cout << "The weight status is: Underweight" << endl;
    else if(bodyMassIndex > 18.5 && bodyMassIndex < 25)
        cout << "The weight status is: Normal" << endl;
    else if (bodyMassIndex > 25 && bodyMassIndex < 30)
        cout << "The weight status is: Overweight" << endl;
    else if( bodyMassIndex >= 30)
        cout << "The weight status is: Obese" << endl;

    return 0;
}

