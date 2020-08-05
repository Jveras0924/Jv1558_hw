
#include <iostream>
using namespace std;


int main()
{
    cout << "Section A" << endl;

    int n2, n, even_num, even_num2;
    int counter = 0;

    even_num = 0;
    even_num2 = 0;

    cout << "Please enter a positive integer: ";

    cin >> n;

    while(n > counter)
    {
        counter++;

        even_num = even_num + 2;

        cout << even_num << endl;
    }
    cout << "Section B" << endl;
    cout << "Please enter a positive integer: ";
    cin >> n2;

    for(counter = 0; n2 > counter; counter ++)
    {
        even_num2 = even_num2 + 2;
        cout << even_num2 << endl;
    }

    return 0;
}

