#include <bits/stdc++.h>
using namespace std;

// TIME: O(n^2)
// SPACE: O(n)->to return answer NOT TO SOLVE PROBLEM
vector<int> brute_force(vector<int> &prices)
{
    int n = prices.size();
    vector<int> discount(n, 0);    //store smallest elem twds right else store 0
    vector<int> answer(n);
    for (int i = 0; i < n; i++)
    {
        // check left elements
        for (int j = i + 1; j <n; j++)
        {
            // smaller element
            if (prices[j] < prices[i])
            {
                discount[i] = (prices[j]);
                break; // as we need only 1st greater
            }
        }
    }
    cout<<"The discounted array is: "<<endl;
    for(auto it:discount){
        cout<<it<<" ";
    }

    // subtract price & discount to get final array:
    for(int i=0;i<n;i++){
        answer[i]=prices[i]-discount[i];
    }

    return answer;
}

// optimise time complexity:
// TIME: O(2n)->worst case
// for loop:O(n) but while loop does NOT run for n times-->st.pop can work for at max n elements NOT more-->O(2n)
// SPACE: O(n)->vector ans + O(n)--> stack
vector<int> finalPrices(vector<int> &prices)
{
    // SMALLEST ELEMENT ON RIGHT SIDE!!
    int n = prices.size();
    vector<int> discount(n, 0);    //store smallest elem twds right else store 0
    vector<int> answer(n);
    stack<int> st; // monotonic stack that stores elements in INCREAsing order

    // start iterating from back of array
    for (int i =n-1; i >=0; i--)
    {
        // pop elements until a greater elem is found:
        while (st.empty() == false && st.top() > prices[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            // no NGE so -1
            discount[i] = 0;
        }
        else if (st.top() <= prices[i])
        {
            // it is NGE
            discount[i] = st.top();
        }
        // after this push current element inside stack:
        st.push(prices[i]);
    }
    cout<<"The discounted array is: "<<endl;
    for(auto it:discount){
        cout<<it<<" ";
    }

    // subtract price & discount to get final array:
    for(int i=0;i<n;i++){
        answer[i]=prices[i]-discount[i];
    }

    return answer;
}

int main()
{
    vector<int> arr = {8, 4, 6, 2, 3};
    // smallestDiscounts element array must contain next smaller elements on left ie {4,2,2,-1,-1}
    // answer array: arr-smallestDiscounts= {4,2,4,2,3}

    // vector<int> ans = brute_force(arr);
    vector<int> ans = finalPrices(arr);

    cout<<"\nThe final prices are: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}