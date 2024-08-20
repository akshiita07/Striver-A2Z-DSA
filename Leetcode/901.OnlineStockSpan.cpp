#include <bits/stdc++.h>
using namespace std;

// TIME: O(n)->for loop traversing backwards
// SPACE: O(n)->for list
class StockSpanner_BruteForce
{
public:
    vector<int> list;
    StockSpanner_BruteForce()
    {
    }

    int next(int price)
    {
        list.push_back(price);
        // returns span
        int count = 1; // not counting current element:
        for (int i = list.size() - 2; i >= 0; i--)
        {
            // backward traversal:
            if (list[i] <= price)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        return count;
    }
};

// OPTIMIZED::
// TIME: O(2n)->to compute PGE
// SPACE: O(n)->stack
class StockSpanner
{
public:
    stack<pair<int, int>> st;
    int index;
    StockSpanner()
    {
        index = -1;
        st.clear();
    }

    int next(int price)
    {
        index++;
        // returns span

        // find index of previous greater element for each new price added
        // ANS count=current index-PGE index
        int pgi;
        while (st.empty() == false && st.top().first <= price)
        {
            st.pop();
        }
        if (st.empty())
        {
            pgi = -1; // no prev greater elem index
        }
        else
        {
            pgi = st.top().second;
        }
        st.push({price,index});

        int count = index - pgi;
        return count;
    }
};