
#include <iostream>
#include <list>
#include <fstream>
#include <string>
using namespace std;

template<class T>
class Stack {
    list<T> data;
public:
    void push(T newItem){data.push_front(newItem);}
    T pop(){return data.pop_front();}
    T top() const {return *data.begin();}
    bool isEmpty() const {return data.size() == 0;}
    int size() const {return data.size();}
    void clear(){data.clear();}
};
bool symbolChecker(ifstream& pascal){

    Stack<char> program;
    char tempSymbol, prevSymbol = '-', prevBracket;
    string begin = "begin", end = "end", cBegin = "Begin", cEnd = "End";
    string tempE, tempB;
    int openPCount = 0, closePCount = 0, openBCount = 0, closeBCount = 0, openCCount = 0, closeCCount = 0;
    int beginCount = 0, endCount = 0, charCount = 0;
    bool pCheck = false, bCheck = false, cCheck = false, allBrackets = false, bNE = false, fail = false;

    while(pascal >> tempSymbol){
        charCount++;
        if(charCount == 1){
            if(tempSymbol == 'b'|| tempSymbol == 'B'){
            }
            else {
                cout << "Begin must be at the top of the page." << endl;
                return fail;
            }
        }

        if(tempSymbol == 'b'|| tempSymbol == 'B') {
             tempB = tempSymbol;
        }
        if(tempSymbol == 'e'|| tempSymbol == 'E') {
            if(prevSymbol == 'B' || prevSymbol == 'b')
                tempB += tempSymbol;
            else
                tempE = tempSymbol;
        }
        if(tempE == end || tempE == cEnd){
            endCount++;
            tempE = "";
        }
        if(tempSymbol == 'n' && prevSymbol == 'e'){
            tempE += tempSymbol;
        }
        if(tempSymbol == 'd' && prevSymbol == 'n'){
            tempE += tempSymbol;
        }
        if(tempSymbol == 'g' && prevSymbol == 'e'){
            tempB += tempSymbol;
        }
        if(tempSymbol == 'i' && prevSymbol == 'g'){
            tempB += tempSymbol;
        }
        if(tempSymbol == 'n' && prevSymbol == 'i'){
            tempB += tempSymbol;
        }
        if(tempB == begin || tempB == cBegin){
            beginCount++;
            tempB ="";
        }
        if(tempE == end || tempE == cEnd){
            endCount++;
            tempE ="";
        }



        if(prevBracket == '('){
            if(tempSymbol == ']' || tempSymbol == '}')
                return fail;
        }
        if(prevBracket == '{'){
            if(tempSymbol == ')' || tempSymbol == ']')
                return fail;
        }
        if(prevBracket == '['){
            if(tempSymbol == ')' || tempSymbol == '}')
                return fail;
        }

        program.push(tempSymbol);
        if(tempSymbol == '(') {
            openPCount++;
            prevBracket = '(';
        }
        if(tempSymbol == ')') {
            closePCount++;
            prevBracket = ')';

        }
        if(tempSymbol == '{') {
            openCCount++;
            prevBracket = '{';
        }
        if(tempSymbol == '}') {
            closeCCount++;
            prevBracket = '}';
        }
        if(tempSymbol == '[') {
            openBCount++;
            prevBracket = '[';
        }
        if(tempSymbol == ']') {
            closeBCount++;
            prevBracket = ']';
        }
        prevSymbol = tempSymbol;
    }
    if(tempSymbol == 'd'){}
    else {
        cout << "Must end with 'end'"<< endl;
        return fail;
    }

    if(openBCount == closeBCount)
        bCheck = true;
    if(openPCount == closePCount)
        pCheck = true;
    if(openCCount == closeCCount)
        cCheck = true;

    if(pCheck && bCheck && cCheck)
        allBrackets = true;
    if(beginCount == endCount){
        bNE = true;
    }

    if(allBrackets && bNE)
        return true;
    else
        return false;

}
void openInputFile(ifstream& inFile){
    string filename;

    cout << "What is the filename: ";
    cin >> filename;
    inFile.open(filename);
    while(!inFile){
        cout << "FILE FAILED TO OPEN!" << endl;
        cout << "What is the filename: ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

int main(){
    ifstream program;
    openInputFile(program);

    if(symbolChecker(program))
        cout << "true";
    else
        cout << "false";

}
