#include <bits/stdc++.h>
using namespace std;

// if(asteroids[i]<asteroids[i+1]){
//     // asteroids[i] will explode
// }else if(asteroids[i]>asteroids[i+1]){
//     // asteroids[i+1] will explode
// }else if(asteroids[i]==asteroids[i+1]){
//     // both will explode
// }

// TIME: O(n)->for loop + O(n)->while loop:that pops/push elements at max for n times = O(2n)
// SPACE: O(n)->list to return answer!
vector<int> asteroidCollision(vector<int> &asteroids)
{
    int n = asteroids.size();
    vector<int> st;
    // for list: top==back      pop==pop_back
    for (int i = 0; i < n; i++)
    {
        // push + elements in list
        if (asteroids[i] >= 0)
        {
            st.push_back(asteroids[i]);
        }
        // for -ve elements:
        else
        {
            // until list has + elements (use absolute value) to collide with
            while (st.empty() == false && st.back() >= 0 && st.back() < abs(asteroids[i]))
            { // top elem explodes
                st.pop_back();
            }
            if (st.empty() == false && st.back() == abs(asteroids[i]))
            {
                // same so pop both
                st.pop_back();
            }
            else if (st.empty() || st.back() < 0)
            {
                // stack is empty or it already contains negative elements so keep on adding -ve elem
                st.push_back(asteroids[i]);
            }
        }
    }
    // elements inside list r remaining asteroids:
    return st;
}

int main()
{
    // array asteroid representing asteroids in a row.
    // absolute value represents its size
    // sign represents its direction (positive meaning right, negative meaning left).
    // If two asteroids meet, the smaller one will explode.
    // If both are the same size, both will explode.
    // Two asteroids moving in the same direction will never meet.
    vector<int> asteroids1 = {5, 10, -5}; // 5,10
    cout << "\nState of asteroid 1 after collision is: ";
    vector<int> ans1 = asteroidCollision(asteroids1);
    for (auto it : ans1)
    {
        cout << it << " ";
    }

    vector<int> asteroids2 = {10, 2, -5}; // 10,-5  -->  10
    cout << "\nState of asteroid 2 after collision is: ";
    vector<int> ans2 = asteroidCollision(asteroids2);
    for (auto it : ans2)
    {
        cout << it << " ";
    }

    vector<int> asteroids3 = {8, -8}; //[]
    cout << "\nState of asteroid 3 after collision is: ";
    vector<int> ans3 = asteroidCollision(asteroids3);
    for (auto it : ans3)
    {
        cout << it << " ";
    }

    return 0;
}