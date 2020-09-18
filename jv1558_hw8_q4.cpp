//  This program prints a randomized pin that is mapped to position 1-5
//  Input from User: Pin Number
//  Output to User: Accepted message or Declined message
/*
#include <iostream>
#include <ctime>
using namespace std;

void printArray(int arr[], int arrSize);
int pinMaping(int randomPin []);
void verifyPin(int num, int randomPin[]);
int main(){

    int num;
    int randomPin[10];

    cout << "Please enter your PIN according to the following mapping: " << endl;
    pinMaping(randomPin);
    cin >> num;
    verifyPin(num,randomPin);

}
void printArray(int arr[], int arrSize) {
    int i;
    for (i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
int pinMaping(int randomPin[]){
    const int pinSize = 10;
    int pin[pinSize]= {0,1,2,3,4,5,6,7,8,9};
    int randomNum, i;

    cout << "PIN:    " ;
    printArray(pin, pinSize);

    cout << "NUM:    ";

    srand(time(0));
    for(i = 0; i < pinSize; i += 1){
        randomNum = rand() % 10;
        randomPin[i] = randomNum;
    }
    printArray(randomPin, pinSize);

}
void verifyPin(int num, int randomPin[]){

    const int pinSize = 10;
    const int userPinSize = 5;
    int const realPin [userPinSize] = {1,2,3,4,5};
    int userPin[userPinSize];
    int rIndex,uIndex, dig, i, correctDigs, i2, temp;

    correctDigs = 0;


    for(i = 0; i <= userPinSize; i += 1 ){
        dig = num % 10;
        userPin[i] = dig;
        num = num / 10;
    }

    if(randomPin[1] == userPin[4]){
        correctDigs += 1;
    }
    if(randomPin[2] == userPin[3]){
        correctDigs += 1;
    }
    if(randomPin[3] == userPin[2]){
        correctDigs += 1;
    }
    if(randomPin[4] == userPin[1]){
        correctDigs += 1;
    }
    if(randomPin[5] == userPin[0]){
        correctDigs += 1;
    }

    if(correctDigs == userPinSize){
        cout << "Your PIN is correct";
    }
    else
        cout << "Your PIN is not correct";

}
*/