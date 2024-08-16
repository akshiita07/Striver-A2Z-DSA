#include <bits/stdc++.h>
using namespace std;
// instead of storing just value inside stack store pair<val,min_element>

class MinStackBruteForce
{
public:
    // TIME: O(1)->constant time
    // SPACE: O(2*n)->storing PAIR!! ->bad😭
    stack<pair<int, int>> st;

    MinStackBruteForce()
    {
        // constructor-initialise variables:
    }

    void push(int val)
    {
        if (st.empty())
        {
            // a
            st.push({val, val});
        }
        else
        {
            // check if min so place min here
            st.push({val, min(val, st.top().second)}); // push pair
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first; // in pair 1st elem is val
    }

    int getMin()
    {
        //  retrieving the minimum element in constant time O(1)
        return st.top().second; // in pair 2nd elem is min
    }
};

// OPTIMAL APPROACH
// STORE ONLY 1 ELEMENT IN STACK!!
class MinStack
{
public:
    // TIME: O(1)->constant time
    // SPACE: O(n)-> 1 elem stored in stack --> OPTIMIZED
    stack<int> st;
    int min_el;

    MinStack()
    {
        // constructor-initialise variables:
        min_el = INT_MAX;
    }

    void push(int val)
    {
        if (st.empty())
        {
            // in first case, 1st val would be min
            min_el = val;
            st.push(val);
        }
        else
        {
            // if value that u r inserting is LARGER so nothing
            if (val > min_el)
            {
                st.push(val);
            }
            else
            {
                // modify min
                st.push(2 * val - min_el);
                min_el = val;
            }
        }
    }

    void pop()
    {
        if (st.empty())
        {
            cout << "\nNo elements";
            return;
        }
        else
        {
            // check if min elem is being popped:
            int elem = st.top();
            st.pop();
            if (elem < min_el)
            {
                // elem is modified value: get prev min
                min_el = 2 * min_el - elem;
            }
        }
    }

    int top()
    {
        if (st.empty())
        {
            cout << "\nNo elements";
            return -1;
        }
        else
        {
            // check if min elem is being popped:
            int elem = st.top();
            if (min_el < elem)
            {
                // elem is NOT modified value
                return elem;
            }
            else
            {
                // elem is modified value
                return min_el;
            }
        }
    }

    int getMin()
    {
        if (min_el == INT_MAX)
        {
            return -1; // no min value
        }
        else
        {
            return min_el;
        }
    }
};

int main()
{
    MinStack minStackObject;
    minStackObject.push(-2);
    minStackObject.push(0);
    minStackObject.push(-3);
    cout << "\nGet min: " << minStackObject.getMin(); // return -3
    minStackObject.pop();
    cout << "\nGet top: " << minStackObject.top(); // return 0
    cout << "\nGet min: " << minStackObject.getMin();
    return 0;
}