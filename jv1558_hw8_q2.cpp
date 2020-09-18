//  This program accepts a word from the user and tells the user if that word is a palindrome
//  Input from User: A word
//  Output to User: tells the user if that word is a palindrome
/*
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);
int main(){
    string word;
    bool palindrome;

    cout << "Please enter a word: ";
    cin >> word;

    palindrome = isPalindrome(word);

    cout << word << " is ";

    if(palindrome == true)
        cout << "a palindrome";
    else//palindrome == false
        cout << "not a palindrome";


    return 0;

}
bool isPalindrome(string str){
    int ind;
    string revWord, tempWord;
    bool palindrome;

    tempWord = str;
    palindrome = false;

    for(ind = tempWord.length() - 1; ind >= 0 ; ind -= 1){
         revWord += tempWord[ind];
    }
    if(tempWord == revWord)
        palindrome = true;

    return palindrome;
}
*/