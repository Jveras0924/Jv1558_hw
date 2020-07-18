// Justin Veras - Extended CS Bridge Summer 2020 - Homework 2 - Question 3//

#include <iostream>
using namespace std;

int main()
{
    //-------------------------------------- Variables --------------------------------------------------------------//
    int johnDays, johnHours, johnMin, billDays, billHours, billMin, jbDays, jbHours, jbMin, totalInMin, totalDays, totalHours;
//----------------------------------- John and Bill's input -----------------------------------------------------------//
    cout << "Please enter the number of days that John worked: ";
    cin >> johnDays;

    cout << "Please enter the number of hours that John worked: ";
    cin >> johnHours;

    cout << "Please enter the number of minutes that John worked: ";
    cin >> johnMin, cout << endl;


    cout << "Please enter the number of days that Bill worked: ";
    cin >> billDays;

    cout << "Please enter the number of hours that Bill worked: ";
    cin >> billHours;

    cout << "Please enter the number of minutes that Bill worked: ";
    cin >> billMin, cout << endl;
//------------------------ Adding John and Bill's Days, Hours, and Mins ---------------------------------------------//
    jbDays = johnDays + billDays;

    jbHours = johnHours + billHours;

    jbMin = johnMin + billMin;
//-------------------------------------- Converting Days to Min -----------------------------------------------------//
    jbDays = jbDays * 1440;
//-------------------------------------- Converting Hours to Min ----------------------------------------------------//
    jbHours = jbHours * 60;
//-------------------------------- Adding Converted Days and Hours to Min -------------------------------------------//
    totalInMin = jbDays + jbHours + jbMin;
//-------------------------------- Convert total into Days -------------------------------------------//
    totalDays = totalInMin / 1440;

    totalInMin = totalInMin % 1440;
//-------------------------------- Convert total remainder into hours  -------------------------------------------//
    totalHours = totalInMin / 60;

    totalInMin = totalInMin % 60;
//-------------------------------- Out put total days hours and min  -------------------------------------------//
    cout << "The total time both of them worked together is " << totalDays << " days, " << totalHours << " hours and " <<
    totalInMin << " minutes.";
    return 0;
}
