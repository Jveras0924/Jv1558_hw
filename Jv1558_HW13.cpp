//not finished got stuck because I have a possible memory leak that I did not understand how to fix,
// I believe this is because tried to implement with pointers outside of my Organism class instead of using the big 3
// method and using pointers instead my class. Let me know if I am on the right track with my idea of the issue with
// this program. thank you.
// P.S. It moves Ants and doodlebugs using polymorphism
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

 bool isNumRight(int num){
    bool isRight;
    if(num == 19 ||num == 39 || num == 59 || num == 79)
        isRight = true;
    else if(num == 99 || num == 119 || num == 139 || num == 159)
        isRight = true;
    else if(num == 179 || num == 199 || num == 219 || num == 239)
        isRight = true;
    else if(num == 259 || num == 279 || num == 299 || num == 319)
        isRight = true;
    else if(num == 339 || num == 359 || num == 379 || num == 399)
        isRight = true;
    else
        isRight = false;

    return isRight;
}
bool isNumLeft(int num){
    bool isLeft;
    if(num == 0 ||num == 20 || num == 40 || num == 60)
        isLeft = true;
    else if(num == 80 || num == 100 || num == 120 || num == 140)
        isLeft = true;
    else if(num == 160 || num == 180 || num == 200 || num == 220)
        isLeft = true;
    else if(num == 240 || num == 260 || num == 280 || num == 300)
        isLeft = true;
    else if(num == 320 || num == 340 || num == 360 || num == 380)
        isLeft = true;
    else
        isLeft = false;

    return isLeft;
}
class Organism{
public:

    Organism();

    int m_getLocation()const{return location;}

    string m_getModel()const {return model;}

    int m_setLocation(int arrPos) { return location = arrPos;}

    virtual void m_move(Organism** &arr, Organism* bug, int oldLoc) {}

    virtual void breed(Organism** &arr, int oldLoc){}

    virtual string m_printModel(){cout << "- "; return "- ";}

    virtual void eatAnts(Organism** &arr, Organism* bug, int oldLoc){}

    Organism& operator =( const Organism* rhs) ;


    int m_setCountdown(int num){ return breedCountDown = num;}

    int m_getCountdown(){return breedCountDown;}

    int breedCountDown;
protected:
    // type of organism
    string model;
    // Location of bug in the world
    int location;
    bool haveBred;
};

 Organism::Organism() {
    model = "- ";
    location = 0;
    breedCountDown = 0;
}
Organism& Organism::operator=(const Organism *rhs) {
    if(this == rhs )
        return *this;
    *this = rhs;
    return *this;

}
class Ant: public Organism{
public:
    Ant();

    void breed(Organism** &arr,int oldLoc);

    void m_move(Organism** &arr, Organism* bug, int oldLoc) override;

    string m_printModel() override {cout << "o "; return "o ";}

};

Ant::Ant() {
    model = "o ";
    location = 0;
    breedCountDown = 0;
}
void Ant::m_move(Organism** &arr, Organism* bug, int oldLoc){
    bool numRight, numLeft;
    int newLocation = 0, count = 0, randomNum, quitCount = 0;
    Organism *temp;

    numRight = isNumRight(oldLoc);
    numLeft = isNumLeft(oldLoc);

    while (count < 1 || quitCount == 4) {
        srand(time(0));
        randomNum = (rand() % 4) + 1;

// move Right
        if (randomNum == 1) {
            if (numRight == false && arr[oldLoc + 1]->m_getModel() == "- ") {
                newLocation = oldLoc + 1;

                temp = arr[oldLoc];
                arr[oldLoc] = arr[newLocation];
                arr[newLocation] = temp;

                arr[oldLoc]->m_setLocation(oldLoc);
                arr[newLocation]->m_setLocation(oldLoc + 1);
            } else {
                randomNum = 2;
                quitCount = quitCount + 1;
            }
        }

// move left,
        if (randomNum == 2) {
            if (numLeft == false && arr[oldLoc - 1]->m_getModel() == "- ") {
                newLocation = oldLoc - 1;

                temp = arr[oldLoc];
                arr[oldLoc] = arr[newLocation];
                arr[newLocation] = temp;

                arr[oldLoc]->m_setLocation(oldLoc);
                arr[newLocation]->m_setLocation(oldLoc - 1);

                count = 1;
            } else {
                randomNum = 3;
                quitCount = quitCount + 1;
            }
        }
// move up , location 0- 19 not allowed to move up
        if (randomNum == 3) {
            if (oldLoc >= 20 && arr[oldLoc - 19]->m_getModel() == "- ") {
                newLocation = oldLoc - 19;

                temp = arr[oldLoc];
                arr[oldLoc] = arr[newLocation];
                arr[newLocation] = temp;

                arr[oldLoc]->m_setLocation(oldLoc);
                arr[newLocation]->m_setLocation(oldLoc - 19);
                count = 1;
            } else {
                randomNum = 4;
                quitCount = quitCount + 1;
            }
        }
// move down, locations 380 - 399 not allowed to move down
        if (randomNum == 4) {
            if (oldLoc <= 379 && arr[oldLoc + 19]->m_getModel() == "- ") {
                newLocation = oldLoc + 19;

                temp = arr[oldLoc];
                arr[oldLoc] = arr[newLocation];
                arr[newLocation] = temp;

                arr[oldLoc]->m_setLocation(oldLoc);
                arr[newLocation]->m_setLocation(oldLoc + 19);

                count = 1;
            } else {
                randomNum = 1;
                quitCount = quitCount + 1;
            }
        }
    }
}
void Ant::breed(Organism** &arr, int oldLoc) {
    bool numRight, numLeft;
    int newLocation, count =0;
    Ant *temp = new Ant;
    numRight = isNumRight(oldLoc);
    numLeft = isNumLeft(oldLoc);

    while(count < 1) {
        if (numRight == false && arr[oldLoc + 1]->m_getModel() == "- ") {
            arr[oldLoc]->m_setCountdown(3);
            newLocation = oldLoc + 1;

            //arr[newLocation] = NULL;
            arr[newLocation] = temp;

            arr[newLocation]->m_setLocation(oldLoc + 1);

            count = 1;

        }
        if (numLeft == false && arr[oldLoc - 1]->m_getModel() == "- ") {
            newLocation = oldLoc - 1;

            //arr[newLocation] = NULL;
            arr[newLocation] = temp;

            arr[newLocation]->m_setLocation(oldLoc + 1);
            count = 1;
        }
        if (oldLoc >= 20 && arr[oldLoc - 19]->m_getModel() == "- ") {
            newLocation = oldLoc - 20;

            //arr[newLocation] = NULL;
            arr[newLocation] = temp;

            arr[newLocation]->m_setLocation(oldLoc - 19);
            count = 1;
        }
        if (oldLoc >= 20 && arr[oldLoc + 19]->m_getModel() == "- ") {
            newLocation = oldLoc + 20;

            //arr[newLocation] = NULL;
            arr[newLocation] = temp;

            arr[newLocation]->m_setLocation(oldLoc + 19);
            count = 1;
        }
    }

}
class DoodleBug : public Organism{
    int lifeCounter;
    public:
    DoodleBug();
    string m_printModel() override {cout << "X "; return "X ";}
    void m_move(Organism** &arr, Organism* bug, int oldLoc) override ;
};

DoodleBug::DoodleBug() {
    model = "X ";
    location = 0;
    breedCountDown = 8;
    lifeCounter = 3;
}
 void DoodleBug::m_move(Organism** &arr, Organism* bug, int oldLoc) {
     bool numRight, numLeft;
     int newLocation = 0, count = 0, randomNum, quitCount = 0;
     Organism *temp;

     numRight = isNumRight(oldLoc);
     numLeft = isNumLeft(oldLoc);

     while (count < 1 || quitCount == 4) {
         srand(time(0));
         randomNum = (rand() % 4) + 1;

// move Right
             if (randomNum == 1) {
                 if (numRight == false && arr[oldLoc + 1]->m_getModel() == "- ") {
                     newLocation = oldLoc + 1;

                     temp = arr[oldLoc];
                     arr[oldLoc] = arr[newLocation];
                     arr[newLocation] = temp;

                     arr[oldLoc]->m_setLocation(oldLoc);
                     arr[newLocation]->m_setLocation(oldLoc + 1);
                 } else {
                     randomNum = 2;
                     quitCount = quitCount + 1;
                 }
             }

// move left,
             if (randomNum == 2) {
                 if (numLeft == false && arr[oldLoc - 1]->m_getModel() == "- ") {
                     newLocation = oldLoc - 1;

                     temp = arr[oldLoc];
                     arr[oldLoc] = arr[newLocation];
                     arr[newLocation] = temp;

                     arr[oldLoc]->m_setLocation(oldLoc);
                     arr[newLocation]->m_setLocation(oldLoc - 1);

                     count = 1;
                 } else {
                     randomNum = 3;
                     quitCount = quitCount + 1;
                 }
             }

// move up , location 0- 19 not allowed to move up
             if (randomNum == 3) {
                 if (oldLoc >= 20 && arr[oldLoc - 19]->m_getModel() == "- ") {
                     newLocation = oldLoc - 19;

                     temp = arr[oldLoc];
                     arr[oldLoc] = arr[newLocation];
                     arr[newLocation] = temp;

                     arr[oldLoc]->m_setLocation(oldLoc);
                     arr[newLocation]->m_setLocation(oldLoc - 19);
                     count = 1;
                 } else {
                     randomNum = 4;
                     quitCount = quitCount + 1;
                 }
             }
// move down, locations 380 - 399 not allowed to move down
             if (randomNum == 4) {
                 if (oldLoc <= 379 && arr[oldLoc + 19]->m_getModel() == "- ") {
                     newLocation = oldLoc + 19;

                     temp = arr[oldLoc];
                     arr[oldLoc] = arr[newLocation];
                     arr[newLocation] = temp;

                     arr[oldLoc]->m_setLocation(oldLoc);
                     arr[newLocation]->m_setLocation(oldLoc + 19);

                     count = 1;
                 } else {
                     randomNum = 1;
                     quitCount = quitCount + 1;
                 }
             }
     }
}

void createWorld(Organism** &arrPtr){
    Organism* base = new Organism[400];
        for(int i = 0; i < 400 ; i += 1 ){
            arrPtr[i] = &base[i] ;
            arrPtr[i]->m_setLocation(i);
        }
}
void printWorld(Organism** &arr){

    for(int i = 0; i < 400; i += 1) {
        arr[i]->m_printModel();
        if (i == 19 || i == 39 || i == 59 || i == 79 || i == 99)
            cout << endl;
        if (i == 119 || i == 139 || i == 159 || i == 179 || i == 199)
            cout << endl;
        if (i == 219 || i == 239 || i == 259 || i == 279 || i == 299)
            cout << endl;
        if (i == 319 || i == 339 || i == 359 || i == 379 || i == 399)
            cout << endl;
    }

}
 void populateWorldAnts( Organism** &arr){
    int randomNum;
    Ant *ant = new Ant[100];

    srand(time(0));

    for(int i = 0; i < 100; i += 1){
        randomNum = (rand() % 400);
        if(arr[randomNum]->m_getModel() == "- ") {
            arr[randomNum] = NULL;
            arr[randomNum] = &ant[i];
            arr[randomNum]->m_setLocation(randomNum);
        }
        else{
            randomNum = (rand() % 400);
            if(arr[randomNum]->m_getModel() == "- ") {
                arr[randomNum] = NULL;
                arr[randomNum] = &ant[i];
                arr[randomNum]->m_setLocation(randomNum);
            }
            else{
                randomNum = (rand() % 400);
                if(arr[randomNum]->m_getModel() == "- ") {
                    arr[randomNum] = NULL;
                    arr[randomNum] = &ant[i];
                    arr[randomNum]->m_setLocation(randomNum);
                }
            }
        }
    }
}
void populateWorldDoodle(Organism** &arr){
    int randomNum;
    DoodleBug* bug = new DoodleBug[5];

    srand(time(0));

    for(int i = 0; i < 5; i += 1){ // need to make sure that the X get placed
        randomNum = (rand() % 400);
        if(arr[randomNum]->m_getModel() == "- ") {
            arr[randomNum] = NULL;
            arr[randomNum] = &bug[i];
            arr[randomNum]->m_setLocation(randomNum);
        }
        else{
            randomNum = (rand() % 400);
            if(arr[randomNum]->m_getModel() == "- ") {
                arr[randomNum] = NULL;
                arr[randomNum] = &bug[i];
                arr[randomNum]->m_setLocation(randomNum);
            }
            else{
                randomNum = (rand() % 400);
                if(arr[randomNum]->m_getModel() == "- ") {
                    arr[randomNum] = NULL;
                    arr[randomNum] = &bug[i];
                    arr[randomNum]->m_setLocation(randomNum);
                }
            }
        }
    }
}
void turnDoodle(Organism** &arr){
    int i;
    for(i = 0; i < 400; i += 1){
        if(arr[i]->m_getModel() == "X ")
            arr[i]->m_move(arr,arr[i],i);
    }
}
void turnAnt(Organism** &arr){
    int i;
    for(i = 0; i < 400; i += 1){
        if(arr[i]->m_getModel() == "o ")
            arr[i]->m_move(arr,arr[i],i);
    }
}
void breedAnt(Organism** &arr){

    for(int i = 0; i <400; i += 1){
        if(arr[i]->m_getModel() == "o")
            arr[i]->breed(arr,i);
    }
}
void breedDoodle(Organism** &arr){
    for(int i = 0; i <400; i += 1){
        if(arr[i]->m_getModel() == "X")
            arr[i]->breed(arr,i);
    }
}

int main(){
    Organism** world;

    world = new Organism*[400];

    cout << "Hit enter to create the world";
    cin.ignore();
    cout << endl;

    createWorld(world);
    printWorld(world);
    cout << endl;

    cout << "Hit enter to populate this world with Doodle bugs";
    cin.ignore();
    cout << endl;

    populateWorldDoodle(world);
    printWorld(world);
    cout << endl;

    cout << "Hit enter to populate this world with ants";
    cin.ignore();
    cout << endl;

    populateWorldAnts(world);
    printWorld(world);
    cout << endl;

    cout << "Hit enter to move DoodleBugs"; // 1
    cin.ignore();
    cout << endl;

    turnDoodle(world);
    printWorld(world);
    cout << endl;

    cout << "Hit enter to move Ants";
    cin.ignore();
    cout << endl;

    turnAnt(world);
    printWorld(world);
    cout << endl;

    cout << "Hit enter to move DoodleBugs"; //2
    cin.ignore();cout << endl;

    turnDoodle(world);
    printWorld(world);
    cout << endl;
    cout << "Hit enter to move Ants";
    cin.ignore(); cout << endl;
    turnAnt(world);
    printWorld(world);

    cout << "Hit enter to move DoodleBugs";// 3
    cin.ignore();

    turnDoodle(world);
    printWorld(world);

    cout << "Hit enter to move and breed Ants";
    cin.ignore();

    turnAnt(world);
    breedAnt(world);
    printWorld(world);

    cout << "Hit enter to move DoodleBugs"; // 4
    cin.ignore();

    turnDoodle(world);
    printWorld(world);

    cout << "Hit enter to move Ants";
    cin.ignore();

    turnAnt(world);
    printWorld(world);

    cout << "Hit enter to move DoodleBugs"; //5
    cin.ignore();

    turnDoodle(world);
    printWorld(world);

    cout << "Hit enter to move Ants";
    cin.ignore();

    turnAnt(world);
    printWorld(world);

    cout << "Hit enter to move DoodleBugs";// 6
    cin.ignore();

    turnDoodle(world);
    printWorld(world);

    cout << "Hit enter to move and breed Ants";
    cin.ignore();

    turnAnt(world);
    breedAnt(world);
    printWorld(world);

    cout << "Hit enter to move DoodleBugs"; // 7
    cin.ignore();

    turnDoodle(world);
    printWorld(world);

    cout << "Hit enter to move Ants";
    cin.ignore();

    turnAnt(world);
    printWorld(world);

    cout << "Hit enter to move and breed DoodleBugs"; //8
    cin.ignore();

    turnDoodle(world);
    breedDoodle(world);
    printWorld(world);

    cout << "Hit enter to move Ants";
    cin.ignore();

    turnAnt(world);
    printWorld(world);

    cout << "Hit enter to move DoodleBugs";// 9
    cin.ignore();

    turnDoodle(world);
    printWorld(world);

    cout << "Hit enter to move and breed Ants";
    cin.ignore();

    turnAnt(world);
    breedAnt(world);
    printWorld(world);

    cout << "Hit enter to move DoodleBugs"; // 10
    cin.ignore();

    turnDoodle(world);
    printWorld(world);

    cout << "Hit enter to move Ants";
    cin.ignore();

    turnAnt(world);
    printWorld(world);

    cout << "Hit enter to move DoodleBugs"; // 11
    cin.ignore();

    turnDoodle(world);
    printWorld(world);

    cout << "Hit enter to move Ants";
    cin.ignore();

    turnAnt(world);
    printWorld(world);

    cout << "Hit enter to move DoodleBugs";// 12
    cin.ignore();

    turnDoodle(world);
    printWorld(world);

    cout << "Hit enter to move Ants";
    cin.ignore();

    turnAnt(world);
    breedAnt(world);
    printWorld(world);


    return 0;
}
