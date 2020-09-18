
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

    int tries = 5;
    int random_num, guess, guess_count ;
    int rangeX = 1, rangeY = 100;
    bool out_of_tries = false;

    srand(time(0));

    random_num = (rand() % 100) + 1;

    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

    guess_count = 1;

    while(out_of_tries == false){
        cout << "Range:[" << rangeX << ", " << rangeY << "], Number of guesses left: " << tries << endl;
        cout << "Your guess: ";
        cin >> guess;

        if(guess == random_num){
            cout << "Congrats! You guessed my number in " << guess_count << " guesses.";
            out_of_tries = true;
        }

        else if(guess != random_num){
               tries = tries - 1;
               if(tries == 0){
                   out_of_tries = true;
                   cout << "Out of guesses! My number is " << random_num;
               }
               else if(guess > rangeX && guess < rangeY && guess < random_num){
                   rangeX = guess + 1;
                   cout << "Wrong! My number is bigger." << endl;
                   cout << endl;
               }
               else if(guess > rangeX && guess < rangeY && guess > random_num){
                   rangeY = guess - 1;
                   cout << "Wrong! My number is smaller." << endl;
                   cout << endl;
               }
        }
        guess_count += 1;

    }


    return 0;



}
