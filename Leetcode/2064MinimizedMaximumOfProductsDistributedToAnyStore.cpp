#include <bits/stdc++.h>
using namespace std;

int findNoOfShops(int products, vector<int> &quantities)
{
    int shopCount = 0;

    for (int i = 0; i < quantities.size(); i++)
    {
        // shopCount += ceil((quantities[i])/products);
        shopCount += ((quantities[i]+products-1)/products);
    }

    return shopCount;
}
int minimizedMaximum(int n, vector<int> &quantities)
{
    int low = 1;
    int high = *max_element(quantities.begin(), quantities.end());
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // check if mid number of products can be distributd to all shops
        int noOfShops = findNoOfShops(mid,quantities);
        if (noOfShops <= n)
        {
            // possible ans but check for MAX
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
    //OR return low;
}

int main()
{
    vector<int> quantities1 = {11, 6}; // 3
    int n1 = 6;
    cout << "\nThe maximum number of products that are given to " << n1 << " stores is: " << minimizedMaximum(n1, quantities1);
    vector<int> quantities2 = {15, 10, 10}; // 5
    int n2 = 7;
    cout << "\nThe maximum number of products that are given to " << n2 << " stores is: " << minimizedMaximum(n2, quantities2);

    return 0;
}