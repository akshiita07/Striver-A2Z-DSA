#include <bits/stdc++.h>
using namespace std;
// STACK: LIFO
// QUEUE: FIFO

class queueUsingStack
{
public:
    // given 2 stacks , implement a queue
    stack<int> st1;
    stack<int> st2;
    // SPACE: O(2* size)->dyamically as using 2 stacks!!

    // TOP/POP-> RETURNS/DELETES FIRST ELEMENT

    void push(int x)
    {
        // TIME: O(2n)-> st1->st2 then st2->st1

        // step1: move elements from stack1 to stack2
        int size1 = st1.size();
        for (int i = 0; i < size1; i++)
        {
            st2.push(st1.top());
            st1.pop();
        }
        // step2: insert x into stack1
        st1.push(x);
        // step3: move elements from stack2 to stack1
        int size2 = st2.size();
        for (int i = 0; i < size2; i++)
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop()
    {
        // TIME: O(1)
        int val = st1.top();
        st1.pop();
        return val;
    }

    int top()
    {
        // TIME: O(1)
        return st1.pop();
    }

    int size()
    {
        // TIME: O(1)
        return st1.size();
    }
}

// THIS PUSH OPERATION TAKES A LOT OF TIME SO MOVE TO APPROACH 2:

class queueUsingStack_Approach2
{
public:
    // given 2 stacks , implement a queue
    stack<int> st1;
    stack<int> st2;
    // SPACE: O(2* size)->dyamically as using 2 stacks!!

    // TOP/POP-> RETURNS/DELETES FIRST ELEMENT

    void push(int x)
    {
        // TIME: O(1)
        // simply push in st1
        st1.push(x);
    }

    int pop()
    {
        // TIME: O(n) not always tho
        // if elem r present in st2 then give that
        if (!st2.empty)
        {
            int val = st2.top();
            st2.pop();
            return val;
        }else{
            // move all elem from st1 to st2
            int size1=st1.size();
            for(int i=0;i<size1;i++){
                st2.push(st1.top());
                st1.pop();
            }
            // then give st2 ka pop
            int val = st2.top();
            st2.pop();
            return val;
        }
    }

    int top()
    {
        // TIME: O(n) not always tho
        // if elem r present in st2 then give that
        if (!st2.empty)
        {
            return st2.top();
        }else{
            // move all elem from st1 to st2
            int size1=st1.size();
            for(int i=0;i<size1;i++){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }

    int size()
    {
        // TIME: O(1)
        return st1.size()+st2.size();
    }
}