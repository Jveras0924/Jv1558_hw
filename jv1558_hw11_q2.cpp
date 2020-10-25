// This program adds the sum of squares of an array and tells if an array is sorted
// User input: two array size and two arrays

#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
int main(){

    int *arr;
    int arrSize;
    int sum;

    cout << "Function A; Sum of Squares: " << endl;
    cout << "Please enter size of your array: ";
    cin >> arrSize;
    arr = new int[arrSize];
    cout << "Please enter " << arrSize <<" integers separated by a space:  ";
    for(int i = 0; i < arrSize; i += 1){
        cin >> arr[i];
    }

    sum = sumOfSquares(arr, arrSize);
    cout << "The Sum of Squares in your Array = ";
    cout << sum;

    cout << endl << "Function B; Is Sorted: " << endl;
    cout << "Please enter size of your array: ";
    cin >> arrSize;
    cout << "Please enter " << arrSize <<" integers separated by a space:  ";
    for(int i = 0; i < arrSize; i += 1){
        cin >> arr[i];
    }

    cout << "Your array is ";
    if(isSorted(arr, arrSize)){
        cout << "sorted";
    }
    else
        cout << "not sorted";

}
int sumOfSquares(int arr[], int arrSize){
    int sum, pow2;
    if(arrSize == 1){
        return (arr[0]) * (arr[0]);
    }
    else{
        sum = sumOfSquares(arr, arrSize - 1);
        pow2  = (arr[arrSize - 1]) * (arr[arrSize - 1]);
        sum += pow2;
        return sum;
    }
}
bool isSorted(int arr[], int arrSize){

    if(arrSize == 1){
        return true;
    }
    else{
        bool sorted;
        sorted = isSorted(arr, arrSize - 1);
        if(sorted == false){
            return false;
        }
        else{
            for(int i = 0; i < arrSize; i += 1){
                if(arr[arrSize - 1] > arr[i]){
                    return true;
                }
                else
                    return false;
            }

        }

    }
}
