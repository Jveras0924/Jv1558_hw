// This program prints out all perfect numbers and amicable numbers in a range between 2 and a particular number greater
// or equal to 2
// Input from the user: a number greater or equal to 2
// Output to the user: list of all perfect numbers and amicable numbers in a particular range
#include <iostream>
#include <cmath>
using namespace std;

void analyzeDivisors(int num, int& outCountDivs,int& outSumDivs);

bool isPerfect(int num);

int main(){
    int m, i, duplicate;
    int outCountDivs, outSumDivs, perfect, count, sumDivTemp;

    cout << "Please enter a positive integer that is >= 2: ";
    cin >> m;

    for(count = 2; count <= m; count += 1){
        perfect = isPerfect(count);
        if(perfect == true)
            cout << "Perfect Number: " << count  << endl;
        analyzeDivisors(count, outCountDivs, outSumDivs);
        sumDivTemp = outSumDivs;
        for(i = 2; i <= m; i += 1){
            analyzeDivisors(i, outCountDivs, outSumDivs);
            if(i == sumDivTemp && count == outSumDivs && count != duplicate)
                if(i != count){
                cout << "Amicable Number: " << count << ", " << i << endl;
                duplicate = i;
                }
        }

    }

}
void analyzeDivisors(int num, int& outCountDivs,int& outSumDivs){

    int count, countDiv, divisorsByDiv, totaldivs;

    outSumDivs = 0;
    divisorsByDiv = 1;
    countDiv = 0;

    for(count = 1; count <= sqrt(num); count += 1){
        if(num % count == 0){
            countDiv += 1;
            outSumDivs += count;
            divisorsByDiv = num / count;
            if(divisorsByDiv != num)
                outSumDivs += divisorsByDiv;
        }
    }
    outCountDivs = countDiv * 2;
    outCountDivs -= 1;

}
bool isPerfect(int num){
    int outCountDivs,outSumDivs;
    bool perfect;
    analyzeDivisors(num, outCountDivs,outSumDivs );
    if(outSumDivs == num)
        perfect =true;
    else
        perfect = false;
    return perfect;
}