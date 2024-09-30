#include <bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    vector<int> st;
    int stSize;
    CustomStack(int maxSize) {
        // Initializes the object with maxSize which is the maximum number of
        // elements in the stack
        stSize=maxSize;
    }

    void push(int x) {
        // Adds x to the top of the stack if the stack has not reached the
        // maxSize
        if (st.size()<stSize) {
            // insert
            st.push_back(x);
        }
    }

    int pop() {
        //  Pops and returns the top of the stack or -1 if the stack is empty.
        if (st.size()==0) {
            return -1;
        }
        int elem=st.back();
        st.pop_back();
        return elem;
    }

    void increment(int k, int val) {
        //  Increments the bottom k elements of the stack by val
        //  If less than k elements in the stack, increment all the elements in the stack.
        int mini=min(k,static_cast<int>(st.size()));
        for(int i=0;i<mini;i++){
            st[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main()
{

    return 0;
}