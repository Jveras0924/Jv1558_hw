
#include <iostream>
using namespace std;

void printArray(int *arr, int arrSize);
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
int main(){

    int const arrSize = 6;
    int arr[arrSize] = {3, -1, -3, 0, 6, 4}, outPos = 0;
    int *arrPtr, *arrPtr2, *arrPtr3, *arrPtr4;
    int outPos2 = 0, outPos3 = 0, outPos4 = 0;
    int *outPosArr = NULL;
    int *outPosArrPtr = NULL;
    arrPtr = arr;
    arrPtr2 = arr;
    arrPtr3 = arr;
    arrPtr4 = arr;

    arrPtr = getPosNums1(arrPtr,arrSize, outPos);
    cout << "getPosNum1: ";
    printArray(arrPtr,outPos);

    arrPtr2 = getPosNums2(arrPtr2,arrSize,&outPos2);
    cout << "getPosNum2: ";
    printArray(arrPtr2, outPos2);

    getPosNums3(arrPtr3, arrSize, outPosArr, outPos3);
    cout << "getPosNum3: ";
    printArray(outPosArr,outPos3);


    getPosNums4(arrPtr4, arrSize , &outPosArrPtr , &outPos4);
    cout << "getPosNum4: ";
    printArray(outPosArrPtr, outPos4);

}
void printArray(int *arr, int arrSize){
    int i;
    for(i = 0; i < arrSize; i += 1){
        cout << *(arr + i) << ' ';
    }
    cout << endl;
}
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int count;
    int *newArrPtr, newArrCount = 0;

    newArrPtr = new int[arrSize];

    outPosArrSize = 0;

    for(count = 0; count < arrSize; count += 1){
        if(arr[count] > 0){
            outPosArrSize += 1;
            newArrPtr[newArrCount] = arr[count];
            newArrCount += 1;
        }
    }

    return newArrPtr;
}
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    int count;
    int *newArrPtr, newArrCount = 0;

    newArrPtr = new int[arrSize];

    for(count = 0; count < arrSize; count += 1){
        if(arr[count] > 0){
            *outPosArrSizePtr += 1;
            newArrPtr[newArrCount] = arr[count];
            newArrCount += 1;
        }
    }

    return newArrPtr;
}
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    int count;
    int newArrCount = 0;

    outPosArr = new int[arrSize];

    for(count = 0; count < arrSize; count += 1){
        if(arr[count] > 0){
            outPosArrSize += 1;
            outPosArr[newArrCount] = arr[count];
            newArrCount += 1;
        }
    }

}
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int count;
    int newArrCount = 0;
    int *newArr;

    newArr = new int[arrSize];

    for(count = 0; count < arrSize; count += 1){
        if(arr[count] > 0){
            *outPosArrSizePtr += 1;
            newArr[newArrCount] = arr[count];
            newArrCount += 1;
        }
    }
    *outPosArrPtr = newArr;



}
