// This program prints the calendar of a particular year
// Input from the user: Year and starting date of the first month of that year
// Output to the user: 12 month calendar of a particular year
/*
#include <iostream>
#include <string>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
int leapYear(int year);
void printYearCalender(int year, int startingDay);

int main(){

    int year, startingDay;

    cout << "Please enter a year using 4 positive integers: ";
    cin >> year;

    cout << "Please enter a starting day only pick integers between and including 1 and 7: ";
    cin >> startingDay;

    printYearCalender(year, startingDay);

    return 0;

}

int printMonthCalender(int numOfDays, int startingDay){

    int countDays, printDays, lastDay;

    printDays = 1;

    cout << "Mon   " << "Tue   " << "Wed   " << "Thr   " << "Fri   " << "Sat   " << "Sun   " << endl;

    for(countDays = 0, printDays = printDays - startingDay; printDays <= numOfDays; countDays += 1, printDays += 1) {
        if (printDays < 8) {
            if (printDays == 0)
                cout << "";
            else if(printDays < 0)
                cout << "      ";
        }
        if (printDays > 0) {
            cout << printDays << "    ";
            if(printDays < 10)
                cout << " ";
            if (countDays == 7 || countDays == 14 || countDays == 21 || countDays == 28 || countDays == 35)
                cout << endl;
        }
    }
    cout << endl;
    lastDay = (countDays - numOfDays + 7) - 5;
    if(numOfDays ==31){
        if(startingDay == 6 || startingDay == 7)
        lastDay -= 7;
    }
    if(numOfDays == 30){
        lastDay -= 1;
        if(startingDay == 7)
            lastDay -= 7;
    }
    if(numOfDays == 29){
        lastDay = startingDay;
    }
    if(numOfDays == 28){
        lastDay -= 3;
        if(lastDay == 0)
            lastDay += 7;
    }
    return  lastDay;
}
int leapYear(int year){
    bool isLeapYear = false;
    int mod4, mod100, mod400;

    mod4 = year % 4;

    mod100 = year % 100;

    mod400 = year %400;

    if(mod4 == 0){
        if(mod100 != 0  ){
            isLeapYear = true;
        }
    }
    if(mod4 == 0)
        if(mod100 == 0)
            if(mod400 == 0)
                isLeapYear = true;

    return isLeapYear;
}
void printYearCalender(int year, int startingDay){

    int countMonth, numOfDays, leap;
    string month;

    leap = leapYear(year);

    for(countMonth = 1; countMonth <= 12; countMonth +=1){
        if(countMonth == 4 || countMonth == 6 || countMonth == 9 || countMonth == 11){
            numOfDays = 30;
        }
        else if(countMonth == 2){
            if(leap == false)
                numOfDays = 28;
            else
                numOfDays = 29;
        }
        else
            numOfDays = 31;
        if(countMonth == 1)
            month = "January ";
        else if(countMonth == 2)
            month = "February ";
        else if(countMonth == 3)
            month = "March ";
        else if(countMonth == 4)
            month = "April ";
        else if(countMonth == 5)
            month = "May ";
        else if(countMonth == 6)
            month = "June ";
        else if(countMonth == 7)
            month = "July ";
        else if(countMonth == 8)
            month = "August ";
        else if(countMonth == 9)
            month = "September ";
        else if(countMonth == 10)
            month = "October ";
        else if(countMonth == 11)
            month = "November ";
        else
            month = "December ";
        cout << month << year << endl;
        startingDay = printMonthCalender(numOfDays, startingDay);
        cout << endl;

        startingDay += 1;
        if(startingDay > 7)
            startingDay -= 7;
    }
}
 */