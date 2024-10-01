#include <bits/stdc++.h>
using namespace std;
/*
bool canArrange(vector<int> &arr, int k)
{
    //  even length n
    int n = arr.size();
    // divide array into exactly n / 2 pairs such that the sum of each pair is divisible by k
    int i=0;
    int j=n-1;
    while(i<j){
        if((arr[i]+arr[j])%k==0){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}
*/
bool canArrange(vector<int> &arr, int k)
{
    //  even length n
    int n = arr.size();
    // divide array into exactly n / 2 pairs such that the sum of each pair is divisible by k

    // store all remaininder
    vector<int> remainders(k, 0);
    for (auto it : arr)
    {
        // count remainders:
        int r = it % k;
        // handle negative remainders:
        if (r < 0)
        {
            r = r + k;
        }
        remainders[r]++;
    }

    // check if remainders with 0 value can form pairs:
    if (remainders[0] % 2 != 0)
    {
        return false;
    }

    // other remainders: from 1 (as we have checked 0)
    for (int i = 1; i < k; i++)
    {
        if (remainders[i] != remainders[k - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
    int k1 = 5;
    cout << "\nArr1: " << canArrange(arr1, k1);
    vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    int k2 = 10;
    cout << "\nArr2: " << canArrange(arr2, k2);

    return 0;
}