// Justin Veras - Extended CS Bridge Summer 2020 - Homework 3 - Question 6//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
//------------------------------------------ Constant ------------------------------------------------------------//
    const double work_hrs_rate = .40;
    const double off_work_hrs_rate = .25;
    const double weekend_rate = .15;
//------------------------------------------ Variables  ------------------------------------------------------------//
    double call_length , call_start_time;
    string day_of_week;
    double cost_of_call;
//------------------------------------------ User Input ------------------------------------------------------------//
    cout << "Please input the day of the week the call took place." << endl;
    cout << "Be sure to input the day in all caps and in two characters. ex. MO for Monday" << endl;
    cout << "Day of week: ";
    cin >> day_of_week;

    cout << "Please input what time of day the call started in 24hr format." << endl;
    cout << "Enter time with a \".\" between the hours and the minuets: ";
    cin >> call_start_time;

    cout << "Please enter the length of the call in minuets: ";
    cin >> call_length;
//------------------------------------------ Set Fixed Decimal -------------------------------------------------------//
    cout << setprecision(2) << fixed;
//---------------------------- Cost of Call Calculations  ------------------------------------------------------------//
    if(day_of_week == "SA" || day_of_week == "SU")
    {
        cost_of_call = call_length * weekend_rate;
        cout << "This call will cost you $ " << cost_of_call;
    }

    else if(day_of_week == "MO" || day_of_week == "TU" || day_of_week == "WE" || day_of_week ==  "TH" || day_of_week == "FR")
    {
        if(call_start_time <  8)
        {
            cost_of_call = call_length * off_work_hrs_rate;
            cout << "This call will cost you $ " << cost_of_call;
        }
        else if(call_start_time > 18)
        {
            cost_of_call = call_length * off_work_hrs_rate;
            cout << "This call will cost you $ " << cost_of_call;
        }
        else if(call_start_time >= 8)
        {
            cost_of_call = call_length * work_hrs_rate;
            cout << "This call will cost you $ " << cost_of_call;
        }
        else if(call_start_time <= 18)
        {
            cost_of_call = call_length * work_hrs_rate;
            cout << "This call will cost you $ " << cost_of_call;
        }
    }
    else
        cout << "Incorrect input please try again.";

    return 0;
}

