//  This program prints a reversed array, an array that removes odd numbers, and an array that moves odd numbers to the
//  from of the list
//  Input from User: None
//  Output to User: reversed array, array that removes odd numbers, array that moves odd numbers to the from of the list
/*
#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
int main(){
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);



    return 0;

}
void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
void reverseArray(int arr[], int arrSize){

    int ind, revInd, temp;

    for(ind = 0, revInd = arrSize - 1; ind <= arrSize / 2; ind += 1, revInd -= 1){
        temp = arr[ind];
        arr[ind] = arr[revInd];
        arr[revInd] = temp;

    }
}
void removeOdd(int arr[], int& arrSize){//does not work for cases where gap larger than 1 between even num

    int ind, temp, arrSizeCount, plusInd;

    arrSizeCount = 0;
    for(ind = 0;ind < arrSize ; ind += 1){
        if(arr[ind] % 2 == 0)
            arrSizeCount += 1;
    }

    for(ind = 0;ind < arrSize ; ind += 1){
        if(arr[ind] % 2 != 0){
            temp =arr[ind];
            arr[ind] = arr[ind +1];
            arr[ind + 1] = temp;
        }
    }
    for(ind = 0;ind <= arrSize ; ind += 1){
            if(arr[ind] % 2 != 0){
                temp = arr[ind];
                arr[ind] = arr[ind + 1];
                arr[ind + 1] = temp;

            }
    }

    arrSize = arrSizeCount;

}
void splitParity(int arr[], int arrSize){

    int indEnd, temp,indStart;

    for(indEnd = arrSize - 1, indStart = 0; indEnd >= 0 ; indEnd -= 1, indStart += 1){
        if(arr[indEnd] % 2 == 0){
            temp = arr[indStart];
            arr[indStart] = arr[indEnd];
            arr[indEnd] = temp;
        }

    }

}
*/