#include <bits/stdc++.h>
using namespace std;
// STACK: LIFO
// QUEUE: FIFO

class stackUsingQueue
{
public:
    // given a queue , implement a stack
    queue<int> q;
    // TOP/POP-> RETURNS/DELETES LAST ELEMENT
    void push(int x)
    {
        // TIME: O(n)-> to rearrange elements where n=size
        int size = q.size();
        q.push(x);
        // on push ..take the first set of elements & move them aage
        for (int i = 0; i < size; i++)
        {
            // add front elements at the END
            q.push(q.front());
            // remove those front elements
            q.pop();
        }
    }
    int pop()
    {
        // TIME: O(1)
        int val = q.front();
        q.pop();
        return val;
    }
    int top()
    {
        // TIME: O(1)
        return q.front();
    }
    int size()
    {
        // TIME: O(1)
        return q.size();
    }
}