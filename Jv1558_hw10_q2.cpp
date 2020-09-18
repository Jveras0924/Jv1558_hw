

#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
int main(){
    int n, *intArr, i, resArrSize = 0;

    cout << "Please input the number of integers you will input into the array: " << endl;
    cin >> n;

    intArr = new int[n];

    cout << "Please input " << n << " integers in the range of 0 to " << n << " separated by a space: " << endl;
    for(i = 0; i < n; i += 1){
        cin >> intArr[i];
    }
    intArr = findMissing(intArr, n, resArrSize);

    cout << "There are " << resArrSize << " missing numbers. " << endl;
    cout << "The missing numbers are listed below: " << endl;

    for(int i = 0; i < resArrSize; i += 1){
        cout << intArr[i] << ' ';
    }
    cout << endl;


    return 0;
}
int* findMissing(int arr[], int n, int& resArrSize){

    int count, i, j, misNum = 0, k;
    int *tempArr = new int[n + 1];
    int *missingNum;

    for( i = 1; i <= n; i += 1){
        tempArr[i] = i;
    }
    count = n + 1;
    for( j = 0; j <= n; j += 1){
        if(arr[j] <= n){
            if(tempArr[arr[j]] != -1) {
                tempArr[arr[j]] = -1;
                count = count - 1;
            }
        }
    }

    missingNum = new int[count];
    for(k = 0; k <= n;  k += 1) {
        if(tempArr[k] != -1){
            missingNum[misNum] = tempArr[k];
            misNum += 1;
        }
    }

    resArrSize = count;
    return missingNum;
    }








