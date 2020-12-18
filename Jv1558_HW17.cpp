/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions.
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>

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
    /*
    void singleCCR(RBTNode<T> *&point);
    void doubleCR(RBTNode<T> *&point);
    void singleCR(RBTNode<T> *&point);
    void doubleCCR(RBTNode<T> *&point);
     */
    void rightRotate(RBTNode<T> *x);
    void leftRotate(RBTNode<T> *x);
    RBTNode<T> *grand(RBTNode<T> *v) const;
    RBTNode<T> *uncle(RBTNode<T> *v) const;
    bool isLeftChild(RBTNode<T> *v) const;
    RBTNode<T> *search( T data ) const;
    int count;
    bool placeItemAtLeaf(RBTNode<T> *newNode);
public:
    RBT() : root(nullptr), count(0) {}

    void insert(T data);
    //void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parent);
    void prettyPrint() const { root->prettyPrint(0); }

    int height() const { return root->height(); }
};

template<class T>
RBTNode<T> *RBT<T>::search( T data ) const
{
    RBTNode<T> *v=root;
    bool absent=false;
    while(!absent && data != v->data ) {
        if(data < v->data && v->left != nullptr )
            v = v->left;
        else if(data > v->data && v->right != nullptr )
            v = v->right;
        else
            absent = true;
    }
    return v;
}

/*
template <class T>
void RBT<T>::doubleCCR(RBTNode<T> *&point) {
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T> *&point) {
    singleCCR(point->left);
    singleCR(point);
}

template <class T>
void RBT<T>::singleCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->left;
    // TODO: ADD ROTATION CODE HERE
}
*/

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
    T data = newNode->data;
    if(count==0) {
        count=1;
        root=newNode;
    }
    else {
        RBTNode<T> *v = search(data);
        if(data < v->data ) {
            count++;
            v->left=newNode;
            newNode->parent = v;
        }
        else if(data > v->data ) {
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
/*
template <class T>
void RBT<T>::singleCCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->right;
    // TODO: ADD ROTATION CODE HERE
}

template <class T>
void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {
    if (point == nullptr) {               // leaf location is found so insert node
        point = new RBTNode<T>(toInsert); // modifies the pointer itself since *point
        // is passed by reference
        point->parent = parent;

        RBTNode<T> *curr_node = point; // curr_node will be set appropriately when walking up the tree
        // TODO: ADD RBT RULES HERE
    } else if (toInsert < point->data) { // recurse down the tree to left to find correct leaf location
        insert(toInsert, point->left, point);
    } else { // recurse down the tree to right to find correct leaf location
        insert(toInsert, point->right, point);
    }
}
*/
template<class T>
void RBT<T>::insert(T data)
{
    RBTNode<T> *x = new RBTNode<T>(data);
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


// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }

    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */

    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
}

