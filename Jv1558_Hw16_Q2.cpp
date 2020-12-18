
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class QueueVector{
public:
    vector<T> data;
public:
    void enqueue(T newItem){data.push_back(newItem);}
    void dequeue(){ data.reserve(data.size()); data.pop_back(); data.reserve(data.size());}
    T top()const {return data[data.size() - 1];}
    int size()const{return data.size();}
    bool isEmpty () const {return data.size() == 0; }
    void clear(){data.clear();}
};

int main(){

    QueueVector<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    q.dequeue();


}

