
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> vector_Create_Array();
void search_Num2(vector<int> num_Vec, int num);
int main2();
int* no_Vector_Create_Array(int& arrSize);
void search_Num(int arr[], int num, int arrSize);
int main1();
int main(){
    cout << "Main 1: " << endl;
    //main1();
    cout << "Main 2: " << endl;
    main2();
}
int main2(){
    vector<int> sequence;
    int num;

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1: " << endl;

    sequence = vector_Create_Array();
    cout << "Please enter the number you would like to search: " << endl;
    cin >> num;

    search_Num2(sequence, num);
}
int main1(){

    int *arrPtr, num, arrSize = 0;


    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1: " << endl;

    arrPtr = no_Vector_Create_Array(arrSize);
    cout << "Please enter the number you would like to search: " << endl;
    cin >> num;

    search_Num(arrPtr,num, arrSize);

}
void search_Num2(vector<int> num_Vec, int num){

    cout << num << " shows in lines ";
    for(int i = 0; i < num_Vec.size(); i += 1){
        if(num_Vec[i] == num){
            cout << i + 1 << ' ';
        }
    }
}

vector<int> vector_Create_Array(){
    vector<int> store_Sec;
    int num;
    bool seen_Negative_One = false;
    while(seen_Negative_One == false){
        cin >> num;
        store_Sec.push_back(num);
        if(num <= -1){
            seen_Negative_One = true;
        }
    }


    return store_Sec;
}
void search_Num(int arr[], int num, int arrSize){

    cout << num << " shows in lines ";
    for(int i = 0; i < arrSize -1; i += 1){
        if(arr[i] == num) {
           cout << i + 1;
        }
    }
}
int* no_Vector_Create_Array(int& arrSize){

    int *newArrPtr, currentSize, currentTotalSize, num;

    newArrPtr = new int[1];
    currentTotalSize = 1;
    currentSize = 0;
    for(int i = 0; num >= 0; i += 1){
        cin >> num;
        newArrPtr[i] = num;
        currentSize += 1;
        if(currentTotalSize == currentSize){
            int *tempArr;
            tempArr = new int[2 * currentTotalSize];
            currentTotalSize *= 2;
            for(int j = 0; j < currentSize; j += 1){
                tempArr[j] = newArrPtr[j];
            }
            delete [] newArrPtr;
            newArrPtr = tempArr;
        }
    }
    arrSize = currentSize;
    return newArrPtr;
}
