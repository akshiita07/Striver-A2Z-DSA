#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    // vector to store dequeue elements:
    vector<int> dq;
    int front;
    int rear;
    int size;
    int capacity;

    MyCircularDeque(int k) {
        // Initializes the deque with a maximum size of k.
        capacity=k+1;
        dq.resize(capacity);
        size=k;
        front=0;
        rear=0;
    }
    
    bool insertFront(int value) {
        if(isFull()==true){
            return false;
        }
        // add at front:
        front=(front-1+capacity)%capacity;
        dq[front]=value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()==true){
            return false;
        }
        // add at last:
        dq[rear]=value;
        rear=(rear+1)%capacity;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()==true){
            return false;
        }
        // remove from front:
        front=(front+1)%capacity;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()==true){
            return false;
        }
        // remove from last:
        rear=(rear-1+capacity)%capacity;
        return true;
    }
    
    int getFront() {
        if(isEmpty()==true){
            return -1;
        }
        // get front:
        int elem=dq[front];
        return elem;
    }
    
    int getRear() {
        if(isEmpty()==true){
            return -1;
        }
        // get last:
        int elem=dq[(rear-1+capacity)%capacity];
        return elem;
    }
    
    bool isEmpty() {
        if(front==rear){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if((rear+1)%capacity==front){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
int main()
{

    return 0;
}