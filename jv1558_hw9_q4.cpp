
#include <iostream>
using namespace std;

void oddsKeepEvenFlip(int arr[],int arrSize);
int main(){
    int arr[6] = {5, 2, 11, 7, 6, 4};

    oddsKeepEvenFlip(arr, 6);


}

void oddsKeepEvenFlip(int arr[],int arrSize){

    int i, j, temp = 0, evenCount = 0;

    for(i = 0, j = arrSize - 1; i < arrSize; i += 1){
        if(arr[i] % 2 == 0) {
            evenCount += 1;
            if(evenCount == 1){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            if(arr[i] % 2 == 0 && arr[i + 1] % 2 != 0){
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i +1] = temp;
            }
        }
    }

    for(i = 0; i < arrSize; i += 1){
        cout << arr[i] << ' ';
    }

}
