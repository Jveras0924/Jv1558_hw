
#include <iostream>
#include <string>
using namespace std;


int main(){

    int n, count, col, row, len;
    string star = "";
    const string start_add = "*";
    const string star_add2 = "**";
    string space = " ";

    cout << "Please enter a number to create an hourglass: ";
    cin >> n;

    len = (2 * n) - 1;

    for(col = n; col >= 1; col --){
        for(row = len; row >= 1; row --){
            if(row >= n - (col - 1) && row <= n + (col - 1))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    for( col = 1; col <= n; col ++){
        for(row = 1; row <= len; row ++){
            if(row >= n -(col -1) && row <= n + (col - 1))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;

    }
    return 0;
}


