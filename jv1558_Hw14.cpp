
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> const &input)
{
    cout << "Min value in array: ";
    cout << input.at(0) << endl;
    cout << "Max value in array: ";
    cout << input.at(1) << endl;
}
void findMinMax(vector<int> &v, vector<int> &temp, int startInd, int endInd);
void compare(vector<int> &v, vector<int> &temp, int startInd, int endInd);
int main(){

    vector<int> test = {10, 1, 12, 19, 10, 23, 2, 14};
    vector<int> res = {0,0};

    findMinMax(test,res,0, 8);

    print(res);


}
void findMinMax(vector<int> &v,vector<int> &temp, int startInd, int endInd){
    if(startInd < endInd) {
        int mid;
        mid = (startInd + endInd) / 2;
        findMinMax(v, temp, startInd, mid);
        findMinMax(v, temp, mid + 1, endInd);
        compare(v, temp, startInd, endInd);

    }

}

void compare(vector<int> &v, vector<int> &temp, int startInd, int endInd){
    int min, max;

    min = v[startInd];
    max = v[startInd];

    while(startInd < endInd){
        if(v[startInd] < min){
            min = v[startInd];
        }
        if(v[startInd] > max){
            max = v[startInd];
        }
        startInd += 1;
    }

    temp[0] = min;
    temp[1] = max;
}