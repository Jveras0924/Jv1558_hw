// This program hides numbers not attached to letter
// Input from User: Sentence with numbers and letter
// Output from User: censors numbers not attached to letters in the inputted sentence
/*
#include <iostream>
#include <string>
using namespace std;

void xOutNums(string lineOfText);
int main(){

    string lineOfText;

    cout << "Please input line of text: " << endl;
    getline(cin , lineOfText);

   xOutNums(lineOfText);


    return 0;
}
void xOutNums(string lineOfText){
    string space = " ", word = "", check = "";
    int i, wordcount = 0, arrSize = 0;
    char w =' ';
    string arr[20];
    int wordLen, count;

    lineOfText = lineOfText + " ";


    for(i = 0; i <= lineOfText.length(); i += 1){
        check = lineOfText[i];
        word = word + lineOfText[i];
        if(check == space){
            wordcount = 0;
            arr[arrSize] = word;
            arrSize += 1;
            word = "";


        }
        else
            wordcount += 1;
    }

    for(i = 0; i < arrSize; i += 1){
        word =arr[i];
        wordLen = word.length() - 1;
        if(word[0] == '0'||word[0] == '1'||word[0] == '3'||word[0] == '4'||word[0] == '5' || word[0] == '6'||
           word[0] == '7'||word[0] == '8'||word[0] == '9'||word[0] == '2'){
            word[0] = 'x';
            for(count = 1; count < wordLen; count += 1){
                if(word[count] == '0'||word[count] == '1'||word[count] == '3'||word[count] == '4'||word[count] == '5' ||
                   word[count] == '6'|| word[count] == '7'||word[count] == '8'||word[count] == '9'||word[count] == '2')
                    word[count] = 'x';
            }
        }
        arr[i] = word;
    }
    for (i = 0; i < arrSize; i++) {
        cout << arr[i];
    }
    cout << endl;

}
*/