// This program outputs a triangle, an opposite triangle, and a ruler
// user input: size of triangles
// set output ruler of size 16

#include <iostream>
using namespace std;

void printTriangle(int n);
void printOppositeTriangle(int n);
void printRuler(int n);
int main(){

    int num;
    cout << "Function A: Print Triangle " << endl;
    cout << "Please enter a positive integer: ";

    cin >> num;
    printTriangle(num);

    cout << "Function B: Print Opposite Triangle " << endl;
    cout << "Please enter a positive integer:  ";

    cin >> num;
    printOppositeTriangle(num);

    cout << "Function C: Print Ruler " << endl;
    printRuler(4);

}
void printTriangle(int n){
    if(n == 1){
        cout << "*" << endl;
    }
    else{
        printTriangle(n - 1);
        for(int i = 0; i < n; i += 1){
            cout << "* ";
        }
        cout << endl;
    }
}
void printOppositeTriangle(int n){
    if(n == 1){
        cout << '*' << endl << '*' << endl;
    }
    else{
        for(int i = 0; i < n ; i += 1){
            cout << "* ";
        }
        cout << endl;
        printOppositeTriangle(n - 1);
        for(int i = 0; i < n ; i += 1){
            cout << "* ";
        }
        cout << endl;
    }
}
void printRuler(int n){
int count = 0;
    if(n <= 1){
        cout << "- " << endl;
    }
    else{
        printRuler(n - 1);
        for(int i = 0; i < n; i +=1){
            cout << "- ";
        }
        cout << endl;
        printRuler(n- 1);

    }

}
