
#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
void printArray(string *sentenceArr, int sentenceArrSize);
int main(){
    string sentence;
    string *sentenceArr;
    int wordsArrSize = 0;

    cout << "Please enter a sentence: " << endl;
    getline(cin, sentence);

    sentenceArr = createWordsArray(sentence,wordsArrSize);
    printArray(sentenceArr,wordsArrSize);

    delete [] sentenceArr;

    return 0;

}
void printArray(string *sentenceArr, int sentenceArrSize){
    for(int i = 0; i < sentenceArrSize; i += 1)
        cout << sentenceArr[i] << ' ';
    cout << endl;
}
string* createWordsArray(string sentence, int& outWordsArrSize){

    string *sentenceArrPtr, word;
    const char space = ' ';
    int i;
    int sentenceArrTotalSize, sentenceArrRealSize;

    sentenceArrPtr = new string[1];
    sentenceArrTotalSize = 1;
    sentenceArrRealSize = 0;


    for(i = 0; i < sentence.length(); i += 1){
        if(sentence[i] == space){
            sentenceArrPtr[sentenceArrRealSize] += word;
            sentenceArrRealSize += 1;
            word = "";
        }
        else
            word += sentence[i];
        if(sentenceArrRealSize == sentenceArrTotalSize){
            string  *tempSentenceArr;
            tempSentenceArr = new string[sentenceArrTotalSize * 2];
            for(int j = 0; j <sentenceArrRealSize; j += 1){
                tempSentenceArr[j] = sentenceArrPtr[j];
            }
            delete []sentenceArrPtr;
            sentenceArrPtr = tempSentenceArr;
            sentenceArrTotalSize *= 2;
        }
    }
    outWordsArrSize = sentenceArrRealSize;

    return sentenceArrPtr;

}
