
#include <iostream>
#include <iomanip>
using namespace std;

class Money{
public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    //Returns the sum of the values of amount1 and amount 2

    friend Money operator -(const Money& amount1, const Money& amount2);
    //Returns amount1 minus amount2

    friend Money operator -(const Money& amount);
    //Returns a negative amount value

    friend bool operator == (const Money& amount1, const Money& amount2);
    //Returns true if amount1 and amount2 have the same value; false otherwise

    friend bool operator <(const Money& amount1, const Money& amount2);
    //Returns true if amount1 is less than amount2; false otherwise

    Money(double dollars, int cents);
    //Initializes object with dollars and cents as the argument

    Money(double dollars);
    //Initializes object so its value is $dollars.00

    Money( );
    //Initializes object so its value is $0.00

    double get_Value() const ;
    //Returns the amount of money recorded in the data

    friend istream& operator >>(istream& ins, Money& amount);
    // Overloads >>

    friend ostream& operator <<(ostream& outs, const Money& amount);
    //overloads <<

private:
    long all_cents;

};

Money operator+(const Money &amount1, const Money &amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

Money operator-(const Money &amount1, const Money &amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator-(const Money &amount) {
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator==(const Money &amount1, const Money &amount2) {
    return (amount1.all_cents == amount2.all_cents);
}

bool operator<(const Money &amount1, const Money &amount2) {
    return (amount1.all_cents < amount2.all_cents);
}

Money::Money(double dollars, int cents) {
    if(dollars*cents < 0){
        cout << "Invalid input for dollars and cents." << endl;
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}

Money::Money(double dollars) {

   all_cents = dollars * 100;


}
Money::Money() : all_cents(0) {

}

double Money::get_Value() const{
    return (all_cents * 0.01);
}

istream &operator>>(istream &ins, Money &amount) {
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins >> one_char;
    if(one_char == '-'){
        negative = true;
        ins >> one_char;
    }
    else
        negative = false;
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    if(one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)){
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digittoint(digit1) * 10 + digittoint(digit2);

    amount.all_cents = dollars * 100 + cents;
    if(negative)
        amount.all_cents = -amount.all_cents;
    return ins;
}
int digittoint(char c){
    return (static_cast<int>(c) - static_cast<int>('0'));
}
ostream& operator <<(ostream& outs, const Money& amount){
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;

    if(amount.all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';
    outs << cents;

    outs << setprecision(3);
    return outs;
}

class Check{
public:

    Check();
    // Constructer Initializer for Check
    //notCashed parameters all numbers are set to 0 and Is cashed is set to false

    Check (int checkNumber, double checkValue, bool cashed);
    //Constructer Initializer for Check
    //Parameters Check Number, Check Value, Is Cashed(True or False)


    int m_getCheckNum() const;
    //Returns the Check Number
    Money m_getCheckAmount();
    //Returns the Check's monetary value
    bool m_getIsCashed() const;
    //Returns the True if the Check was cashed


private:
    int checkNum;
    //The number associated with the check
    Money checkAmount ;
    // The amount of money the check is worth
    bool isCashed;
    // Whether or not the check was cashed

public:
    void output();

    void input();
};
int Check :: m_getCheckNum() const{
    return checkNum;
}
Money Check :: m_getCheckAmount(){
    return checkAmount.get_Value();
}

bool Check::  m_getIsCashed() const{
    if(isCashed == true)
        return true;
    else
        return false;

}

Check::Check() { // not working needs to be fixed
    Money check(0);

    checkAmount = check;
    checkNum = 0;
    isCashed = false;
}

Check::Check(int checkNumber, double checkValue, bool cashed){
    checkNum = checkNumber;
    checkAmount = checkValue;
    isCashed = cashed;

}

void Check::output( ) {
    cout << "The check number is: ";
    cout << checkNum << endl;

    cout << "The check amount is: ";
    cout << checkAmount << endl;

    if(isCashed)
        cout << "The check is cashed" << endl;
    else
        cout << "The check has not been cashed" << endl;

}

void Check::input( ) {
    char yorN;
    cout << "Please input a check number: ";
    cin >> checkNum;

    cout << "Please enter a check amount (Please input amount in this '$0.00' format: ";
    cin >> checkAmount;

    cout << "Is your check cashed? Type Y for yes and N for No: ";
    cin >> yorN;

    if(yorN == 'Y' || yorN == 'y')
        isCashed = true;
    else if(yorN == 'N' || yorN == 'n')
        isCashed = false;
    else
        cout << "Entered illegal character" << endl;
}


int main(){
    //Creates vars for deposits, old account, old + deposits, and num of deposits
    int numOfDep = -2;
    Money depositBalance, oldAccountBalance, oldPlusDeposit;
    Money* deposits;

    //Previous statement balance inputted here
    cout << "Please enter your old account balance in this format '$0.00': ";
    cin >> oldAccountBalance;

    //While loop allows user to input the number of deposits made to account after the previous statement balance
    // only allows positive ints or 0
    while(numOfDep < -1 ) {
        cout << "How many deposits has your account had since your old account balance was calculated? " << endl
             << "(Please enter a positive integer or 0 if you do not wish to input any deposits):  ";
        cin >> numOfDep;
        if(numOfDep < 0) {
            cout << "Illegal expresion entered. Please try again. (Note: if you do not wish to enter deposits" <<
            endl << "please enter 0): ";
        }
    }
    // Dynamic array of predefined type money is created to store all deposits
    deposits = new Money[numOfDep];

    // Only activated if deposits were made during this cycle
    if(numOfDep >= 1) {
        cout << "Please input each deposit in this format '$0.00' and hit enter after each inputted deposit: ";
        // For loops stores all deposits in dynamic array and adds the deposits to deposit balance
        for (int i = 0; i < numOfDep; i += 1) {
            cin >> deposits[i];
            depositBalance = depositBalance + deposits[i];

        }
    }
    cout << "The total of your deposits is: " << depositBalance << endl;

    // Gets the sum of the old balance and the deposit balance and outputs it to the user
    oldPlusDeposit = oldAccountBalance + depositBalance;

    cout << "Your old account balance combined with your deposits is: ";
    cout << oldPlusDeposit;
    cout << endl;

    // Creates a vars for checks that need to be added to the balance, and number of checks to be balanced
    Check* checksToBalance;
    int numOfChecks = -2, cashedCounter = 0, unCashedCounter = 0, cashedCounter2 = 0, unCashedCounter2 = 0;
    Money checkTotal, cashedTotal, unCashedTotal;

    // While loop allows user to input the number of checks to be balanced, valid inputs are positive ints or 0
    while(numOfChecks < -1) {
        cout << "How many checks do you have to balance this cycle?(Please input a positive number or 0" << endl
        << "if you do not wish to balance any checks): ";
        cin >> numOfChecks;
        if(numOfChecks < 0){
            cout << "Illegal expresion entered. Please try again. (Note: if you do not wish to enter deposits" <<
            endl << "please enter 0): ";
        }
    }
    // Creates a dynamic array to store check info
    checksToBalance = new Check[numOfChecks];
    // For loop allows user to input checks, adds total, and counts the number of cashed and uncashed checks
    if(numOfChecks > 0) {
        for (int i = 0; i < numOfChecks; i += 1) {
            checksToBalance[i].input();
            checkTotal = checkTotal + checksToBalance[i].m_getCheckAmount();

            if(checksToBalance[i].m_getIsCashed() == true)
                cashedCounter += 1;
            else
                unCashedCounter += 1;
        }
    }

    Check* cashedChecks = new Check[cashedCounter];
    Check* unCashedChecks = new Check[unCashedCounter];

    for(int i = 0; i < numOfChecks; i += 1){
        if(checksToBalance[i].m_getIsCashed() == true){
            cashedChecks[cashedCounter2] = checksToBalance[i];
            cashedCounter2 += 1;
            cashedTotal = cashedTotal + checksToBalance[i].m_getCheckAmount();
        }
        else{
            unCashedChecks[unCashedCounter2] = checksToBalance[i];
            unCashedCounter2 += 1;
            unCashedTotal = unCashedTotal + checksToBalance[i].m_getCheckAmount();
        }

    }

    cout << endl << "The total value of your checks is: ";
    cout << checkTotal << endl;

    cout << "The total value of only your cashed checks is: ";
    cout << cashedTotal << endl;

    cout << "The total value of only your un-cashed checks is: ";
    cout << unCashedTotal << endl;

    // Creates vars for new account balance including cashed and uncashed, and just cashed
    Money newAccountBalanceC, newAccountBalanceUNC;

    newAccountBalanceC = oldPlusDeposit - cashedTotal;

    newAccountBalanceUNC = oldPlusDeposit - checkTotal;

    cout << "Your new account balance including just cashed checks is(What the bank says your account balance is): ";
    cout << newAccountBalanceC << endl;

    cout << "Your new account balance including both cashed and un-cashed(Your real balance): ";
    cout << newAccountBalanceUNC << endl;

    Money difference;
    difference =  newAccountBalanceC - newAccountBalanceUNC;
    cout << "The difference between what the bank says your balance is and your actual balance is: ";
    cout << difference << endl << endl;


    cout << "Below is a list of your cashed checks" << endl;

    for(int i = 0; i < cashedCounter; i += 1){
        cashedChecks[i].output();

        cout << endl;
    }

    cout << "Below this statement is a list of your un-cashed checks" << endl;

    for(int i = 0; i < unCashedCounter; i += 1){
        unCashedChecks[i].output();

        cout << endl;
    }

    delete [] deposits;
    delete [] checksToBalance;
    delete [] cashedChecks;
    delete [] unCashedChecks;

    return 0;
}

