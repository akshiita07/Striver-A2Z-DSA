#include <bits/stdc++.h>
using namespace std;
// arrays: stored in contiguous memory locations so cannot insert new element at end

// LINKED LIST:
// NOT STORED IN CONTIGUOUS MEMORY LOCATIONS
// can easily INSERT NEW ELEMENTS
// STRUCTURE OF LL:: along with DATA it also stores NEXT pointer--> use self defined data type:struct/class

struct Node{    //name of our data type is Node
    int data;       //stores data
    Node* next;     //pointer of data type Node that points to next memory location

    // constructor to initialise objects data & next of structure
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
};
// DIADVANTAGE OF CLASS-> DOES NOT SUPPORT OOPS-> no encapsulation,abstraction,inheritance

// so use class:
class NodeClass{    //name of our data type is Node
    public:
    int data;       //stores data
    NodeClass* next;     //pointer of data type Node that points to next memory location

    // constructor to initialise objects data & next of structure
    NodeClass(int data1,NodeClass* next1){
        data=data1;
        next=next1;
    }
};

// starting point of LL: HEAD of LL
// the last element of LL: TAIL of LL has next=nullptr

// where is LL used-> stacks,queues         REAL->browsers->arrows to go back & forward in tabs


// MEMORY USED:
// 32 BIT COMP: int-4bytes pointer-4bytes so total 8 bytes
// 64 BIT COMP: int-4bytes pointer-8bytes so total 12 bytes

void memoryLoc()
{
    // &:GIVES MEMORY LOCATIONS
    // we cannot store a memory location SO WE STORE A POINTER TO IT
    int x=7;
    int *y=&x;      //pointer y stores memory location of x
    cout<<"x is: "<<x<<endl;
    cout<<"pointer y is: "<<y<<endl;
}

int main()
{
    // memoryLoc();

    Node* x=new Node(7,nullptr);     //creates a new node with data=7 & next=nullptr
    // x is pointer to memory location
    cout<<x<<endl;
    // to access from pointer use arrow fnc ->
    cout<<"The data of pointer x is: "<<x->data<<endl;
    cout<<"The next pointer of pointer x is: "<<x->next<<endl;    //0 because nullptr

    // to create just an object:
    Node obj= Node(404,nullptr);
    cout<<"The data of object is: "<<obj.data<<endl;
    cout<<"The next pointer of object is: "<<obj.next<<endl;    //0 because nullptr

    NodeClass* cl=new NodeClass(3,nullptr);
    cout<<"The data of pointer cl from class node is: "<<cl->data<<endl;

    return 0;
}
