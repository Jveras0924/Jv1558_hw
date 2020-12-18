// implementation of RedBlackTree
// does not allow duplicate items
//==============================================
// GENERAL BINARY SEARCH TREE METHODS
//==============================================
// method search starts at root looking for that item
// returns either node where found, or failing that,
// position where should be attached
// asssumes root!=null

//need to allow it to take duplicates into a linked list at the point of dupicate value
#include <iostream>
#include <math.h> // for asserting height
#include <queue>
#include <ctime>
#include <queue>
#include <vector>
using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c==0)?1:0;
}

template <class T>
class RBTNode {
    RBTNode<T> *parent, *left, *right;
    T data;
    int color;

public:
    RBTNode(T data)
            : data(data),
              color(RED),
              parent(nullptr),
              left(nullptr),
              right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);
    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T> *node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T> *node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T> *root;
    void rightRotate(RBTNode<T> *x);
    void leftRotate(RBTNode<T> *x);
    RBTNode<T> *grand(RBTNode<T> *v) const;
    RBTNode<T> *uncle(RBTNode<T> *v) const;
    bool isLeftChild(RBTNode<T> *v) const;
    RBTNode<T> *search( T it ) const;
    int count;
    bool placeItemAtLeaf(RBTNode<T> *newNode);
    bool oddTree;
    int num;
    void go(RBTNode<T>* root,vector<int>& inorder){
        if (root == nullptr)
            return;
        go(root->left,inorder);
        inorder.push_back(root->data);
        go(root->right,inorder);
    }


public:
    vector<T> v;
    RBT() : root(nullptr), count(0), num(0){}
    void insert(T it);
    void prettyPrint() const { root->prettyPrint(0); }
    void printLevelOrder();
    int height() const { return root->height(); }
    void printInOrder(RBTNode<T>* node);
    void printInOrder(){printInOrder(root);}
    bool getOddTree() const {return oddTree;}
   // T findMedian(RBTNode<T>* node);
   // T findMedian(){return findMedian(root);}
    T findMax(RBTNode<T>* root);
    T findMax(){return findMax(root);}
    //this code super important
    T findMedian(){
        vector<int> inorder;
        go(root, inorder);
        if(inorder.size() % 2 == 0){
            int i;
            i = (inorder.size())/2;
            i = ((inorder[i] + inorder[i +1])/2);
            return i;

        }
        else{
            int i;
            i = ((inorder.size())/ 2 );
            i = inorder[i];
            return i;
        }

    }
    RBTNode<T>* getroot(){return root;}
};

template<class T>
RBTNode<T> *RBT<T>::search( T it ) const
{
    RBTNode<T> *v=root;
    bool absent=false;
    while( !absent && it!=v->data ) {
        if( it<v->data && v->left!=nullptr )
            v = v->left;
        else if( it>v->data && v->right!=nullptr )
            v = v->right;
        else
            absent = true;
    }
    return v;
}

template<class T>
void RBT<T>::rightRotate(RBTNode<T> *x)
{
    RBTNode<T> *y = x->left;
    x->left = y->right;
    if( y->right!=nullptr)
        y->right->parent=x;
    y->parent = x->parent;
    if( x->parent==nullptr )
        root=y;
    else if( x==x->parent->left )
        x->parent->left=y;
    else
        x->parent->right=y;
    y->right=x;
    x->parent=y;
}

template<class T>
void RBT<T>::leftRotate(RBTNode<T> *x)
{
    RBTNode<T> *y = x->right;
    x->right = y->left;
    if( y->left!=nullptr )
        y->left->parent = x;
    y->parent = x->parent;
    if( x->parent==nullptr )
        root=y;
    else if( x== x->parent->left )
        x->parent->left=y;
    else
        x->parent->right=y;
    y->left=x;
    x->parent=y;
}

template<class T>
RBTNode<T> *RBT<T>::grand(RBTNode<T> *v) const
{
    if( v==root || v->parent==root)
        return nullptr;
    else
        return v->parent->parent;
}
template<class T>
RBTNode<T> *RBT<T>::uncle(RBTNode<T> *v) const {
    if( v==root || v->parent==root )
        return nullptr;
    else if( isLeftChild(v->parent) )
        return grand(v)->right;
    else
        return grand(v)->left ;
}
template<class T>
bool RBT<T>::isLeftChild(RBTNode<T> *v) const {
    return (v!=root && v==v->parent->left);
}

template<class T>
bool RBT<T>::placeItemAtLeaf(RBTNode<T> *newNode)
{
    T it = newNode->data;
    if(count==0) {
        count=1;
        root=newNode;
    }
    else {
        RBTNode<T> *v = search(it);
        if( it < v->data ) {
            count++;
            v->left=newNode;
            newNode->parent = v;
        }
        else if( it > v->data ) {
            count++;
            v->right = newNode;
            newNode->parent = v;
        }
        else {
            return false;
        }
    }
    return true;
}
template<class T>
void RBT<T>::insert(T it)
{
    num++;
    if(num % 2 == 0){
        oddTree = false;
    }
    else
        oddTree = true;
    RBTNode<T> *x = new RBTNode<T>(it);
    if( !placeItemAtLeaf( x ) )
        return;
    x->color = RED;
    while( x!=root && x->parent->color==RED) {
        RBTNode<T> *y = uncle(x);
        if( y!=nullptr && y->color==RED) {   // move red-red problem up tree
            x->parent->color=BLACK;
            y->color=BLACK;
            grand(x)->color= RED;
            x=grand(x);
        }
        else {     // uncle is BLACk; fix with rotation or two
            bool parentWasLeftChild = isLeftChild(x->parent);
            bool wasLeftChild = isLeftChild(x);
            // if you zigzag from grandparent to node, need double rotation
            // this is the first rotation
            if( parentWasLeftChild && !wasLeftChild ) {
                x= x->parent;
                leftRotate(x);
            }
            else if( !parentWasLeftChild && wasLeftChild ) {
                x= x->parent;
                rightRotate(x);
            }
            // in any event you finish off with a rotation
            x->parent->color = BLACK;
            grand(x)->color = RED;
            if( parentWasLeftChild )
                rightRotate(grand(x));
            else
                leftRotate(grand(x));
        }//else
    }//while
    root->color= BLACK;
}
//need drill this in memory
template<class T>
void RBT<T>::printInOrder(RBTNode<T>* node) {
    if(node != nullptr){ // This insures that node is not null
        printInOrder(node->left);//recursively goes down the left side of the tree
        cout << node->data << " ";// prints out the data starting from the bottom left side of the tree
        printInOrder(node->right);// recursively goes down the right side of the tree

    }

}
//needed drill this in memory
template<class T>
void RBT<T>::printLevelOrder() {
    if(root == nullptr)
        return;
    queue<RBTNode<T>*> q; // creating a queue to store nodes
    q.push(root); // pushing the root node onto the queue
    while(!q.empty()){ // while the queue is not empty
        RBTNode<T>* temp = q.front(); // set temp node equal to oldest node in the queue
        q.pop(); // pops the oldest node off the queue
        cout << temp->data << ' ';
        if(temp->left != nullptr)
            q.push((temp->left));
        if(temp->right != nullptr)
            q.push(temp->right);
    }
}

//needed for test drill this in memory
template<class T>
T RBT<T>::findMax(RBTNode<T>* root) {
    if(root == nullptr)
        return -1;
    T max = root->data;
    T lMax = findMax(root->left);
    T rMax = findMax(root->right);
    if(lMax > max)
        max = lMax;
    if(rMax > max)
        max = rMax;
    return max;


}

    /*
    if(v.size() % 2 == 0){
        T i;
        i = (v.size() - 1)/2;
        i = ((v[i] + v[i +1])/2);
        return i;

    }
    else{
        T i;
       i = ((v.size())/ 2 );
        i = v[i];
        return i;
    }
*/



// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int max, med;
    int count = 19;
/*
    for (int i = 0; i < count; i++) {
        b.insert(i+ 1);
    }
*/
    b.insert(1);
    b.insert(2);
    b.insert(3);
    b.insert(4);
    b.insert(5);
    b.insert(6);
    b.insert(7);
    b.printInOrder();
/*
    b.prettyPrint();
    b.printInOrder();
    cout << endl;
    b.printLevelOrder();
    cout << endl;
    */
    //cout << b.findMax();
    //cout << b.findMedian();

}

