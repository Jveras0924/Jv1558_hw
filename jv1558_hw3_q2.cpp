// Justin Veras - Extended CS Bridge Summer 2020 - Homework 3 - Question 2//

#include <iostream>
#include <string>
using namespace std;

int main()
{
//------------------------------------------------- Constants  ------------------------------------------------------//
    const int freshmanYear = 4;
    const int sophomoreYear = 3;
    const int juniorYear = 2;
    const int seniorYear = 1;
//------------------------------------------------- Variables ------------------------------------------------------//
    int graduationYear, currentYear, yearInCollege;

    string studentName;
//------------------------------------------------- User Input ------------------------------------------------------//
    cout << "Please enter your name: ";

    cin >> studentName;

    cout << "Please enter your graduation year: ";

    cin >> graduationYear;

    cout << "Please enter current year: ";

    cin >> currentYear;
//------------------------------------------------- Student Status ------------------------------------------------------//
    yearInCollege = graduationYear - currentYear;

    if(currentYear >= graduationYear)
        cout << studentName << ", you Graduated";
    else if (yearInCollege == freshmanYear)
        cout << studentName << ", you are a Freshman";
    else if (yearInCollege == sophomoreYear )
        cout << studentName << ", your are a Sophomore";
    else if (yearInCollege == juniorYear )
        cout << studentName << ", your are a Junior";
    else if (yearInCollege == seniorYear )
        cout << studentName << ", your are a senior";
    else
        cout << studentName << ", you are not in college yet";


    return 0;
}
