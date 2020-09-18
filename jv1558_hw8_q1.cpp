//  This program finds and the smallest value in a list of 20 and prints its location to the user
//  User input: 20 integers
//  Output: location of the smallest value in the list
/*
#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);
int main(){
    const int listSize = 20;
    int list[listSize];
    int min, count, n, listNum;

    cout << "Please enter 20 integers separated by a space: " << endl;
    for(count = 0; count < listSize; count += 1){
        cin >> n;
        list[count] = n;
    }

    min = minInArray(list,listSize);


    cout << "The minimum value is " << min << ", and it is located in the following indices: ";
    for(count = 0; count <= listSize; count += 1){
        listNum = list[count];
        if(listNum == min)
            cout << count << " ";
    }
    return 0;
}
int minInArray(int arr[], int arrSize){

    int count1,minVal, testVal1;

    minVal = arr[0];

    for(count1 = 0;count1 < arrSize ; count1 += 1){
        testVal1 = arr[count1];
        if(testVal1 <= minVal)
            minVal = testVal1;
    }
    return minVal;
}
*/