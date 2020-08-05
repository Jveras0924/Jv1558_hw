
#include <iostream>
using namespace std;

int main() {

    int n, num, testNum, even, odd, testNum2;
    const int isolate_place1 = 10;
    const int remove_place1 = 10;

    cout << "Please enter a positive integer (n) the program will print out all numbers between 1 and n, that " << endl
         << "have more even digits that odd digits" << endl << "Enter n: ";
    cin >> n;


    even = 0;
    odd = 0;

    for(num = 1; num <= n; num ++) {
        testNum = num;

        while (testNum > 0) {
            testNum = testNum % isolate_place1;
            if (testNum == 2 || testNum == 4 || testNum == 6 || testNum == 8 || testNum == 0) {
                even = even + 1;
            } else if (testNum == 1 || testNum == 3 || testNum == 5 || testNum == 7 || testNum == 9) {
                odd = odd + 1;
            }
            testNum = num / remove_place1;

            if (testNum == 2 || testNum == 4 || testNum == 6 || testNum == 8 || testNum == 0) {
                even = even + 1;
            }
            else if (testNum == 1 || testNum == 3 || testNum == 5 || testNum == 7 || testNum == 9) {
                odd = odd + 1;
            }
            testNum = testNum / remove_place1;
        }

        if (even > odd) {
            cout << num << endl;
            even = 0;
            odd = 0;
        } else {
            even = 0;
            odd = 0;
        }
    }



    return 0;

}

