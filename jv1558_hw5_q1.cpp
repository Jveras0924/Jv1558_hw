
#include <iostream>
using namespace std;

int main(){

    int n, line_count, product, rem, output  ;

    cout << "Please enter a positive integer: " << endl;
    cin >> n;

    for(line_count = 1; line_count <= n; line_count += 1) {
       for(product = 1; product <= n; product += 1){
           output = line_count * product;
           cout << output;
           rem = output / 10;
           if(output <= 9 )
               cout << "    ";
           else if(output <= 99 )
               cout << "   ";
           else if(output <= 999)
               cout << "  ";
           else
               cout << " ";
       }
       cout << endl;
    }
    cout << endl;
    return 0;
}
