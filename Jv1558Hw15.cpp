#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
using namespace std;
struct Node;

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
class Employee{
public:
    //Constructors
    Employee();

    Employee(string &eName, int eID, double eHourlyPay);

    //Acceors
    string m_getName() const{return name;}
    int m_getID() const {return id;}
    double m_getHourlyPay() const{return hourlyPay;}
    int m_getHoursWorked() const{return hoursWorked;}
    double m_getWage() const{return wage;}
    bool m_getSorted() const{return sorted;}
    //Mutators
    string m_setName(string newName){return name = newName;}
    int m_setId(int newID){return id = newID;}
    double m_setHourlyPay(double newHourlyPay){return hourlyPay = newHourlyPay;}
    int m_setHoursWorked(int newHoursWorked){return hoursWorked = newHoursWorked;}
    double m_setWage(double newWage){return wage = newWage;}
    bool m_setSorted(bool t) {return sorted = t;}


private:
    string name;
    int id;
    double hourlyPay;
    int hoursWorked;
    double wage;
    bool sorted;

};

Employee::Employee() {
    name = "";
    id = 0;
    hourlyPay = 0;
    hoursWorked = 0;
    wage = 0;
    sorted = false;
}

Employee::Employee(string &eName, int eID, double eHourlyPay) {
    name = eName;
    id = eID;
    hourlyPay = eHourlyPay;
    hoursWorked = 0;
    wage = 0;
    sorted = false;

}

struct Node{
    Employee *data;
    Node *next;
    Node *prev;
};

class LList {
private:
    Node* start;
public:
    LList(){start = NULL;}
    void m_addEmployee(int id, double hourly, string name);
    Node* m_getStart() const{return start;}

};

void LList::m_addEmployee(int id, double hourlyRate, string name) {
    Employee *e = new Employee(name, id, hourlyRate);
    Node *q = new Node;
    q->data = e;
    q->next = nullptr;
    q->prev = nullptr;
    if(start == nullptr){
        start = q;
        return;
    }else{
        Node *p = start;
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = q;
        q->prev = p;
    }

}
int main(){
    ifstream inFile1, inFile2;
    LList head;
    int tempID;
    double tempHourlyPay;
    string tempName;
    int counter = 0;

    openInputFile(inFile1);

    while(inFile1 >> tempID >> tempHourlyPay){
        getline(inFile1,tempName);
        head.m_addEmployee(tempID,tempHourlyPay,tempName);
        counter += 1;

    }

    inFile1.close();
    openInputFile(inFile2);

    int file2Id[50];
    int file2Hours[50];

    Node *p = head.m_getStart();

    cout << "****** PAYROLL INFORMATION ******" << endl;

    while(inFile2 >> file2Id[counter]){
        inFile2 >> file2Hours[counter];
        counter++;
    }


    while(p!=nullptr){
        double pay = 0.00;
        for(int i = 0; i < counter; i++){
            if(p->data->m_getID() == file2Id[i]){
                pay += p->data->m_getHourlyPay() * file2Hours[i];
            }
        }

        cout << p->data->m_getName() << "\t" << "$"<< pay << endl;
        p = p->next;
    }

    cout << "****** END PAYROLL INFORMATION ******" << endl;
/*
    while(inFile2 >> tempID >> tempHours){
        getWage(head, tempID,tempHours);
    }

    cout << "****** PAYROLL INFORMATION ******" << endl;
    cout << "****** END PAYROLL INFORMATION ******" << endl;
*/
    return 0;
}

// need to sort list in decending order then create linked list class