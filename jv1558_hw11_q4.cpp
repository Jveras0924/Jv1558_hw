// This program outputs the lowest cost of movement in an array where you can only move 1 or two spaces each turn

#include <iostream>
using namespace std;

int jumpIt(int arr[], int arrSize);
int main(){
    int sum;

    int arr[6]= {0, 3, 80, 6 ,57, 10};

    sum = jumpIt(arr, 6);
    cout << "The lowest movement cost is: ";
    cout << sum;

    return 0;
}
int jumpIt(int arr[], int arrSize){
    int sum;
    if( arrSize <= 1){
        return arr[0];
    }
    else {
        sum = jumpIt(arr, arrSize - 1);
        if (arr[arrSize] < arr[arrSize - 1] && arr[arrSize] > -1) {
            return sum;
        }
        else{
            sum += arr[arrSize - 1];
            return sum;
        }
    }

}
