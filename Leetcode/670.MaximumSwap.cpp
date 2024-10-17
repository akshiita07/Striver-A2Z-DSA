#include <bits/stdc++.h>
using namespace std;

int maximumSwap(int num)
{
    int number=num;
    // find max digit & its index
    // swap this max digit with its left index

    // convert digits into array:
    vector<int> digits;
    while (num > 0)
    {
        digits.push_back(num % 10);
        num = num / 10;
    }
    reverse(digits.begin(),digits.end());

    int n = digits.size();
    int maxInd = n-1;
    vector<int> rightMax(n);

    // fill rightMax[] which stores the index of the maximum digit to the right for each index
    for (int i = n-1; i >=0; i--)
    {
        if (digits[i] > digits[maxInd])
        {
            maxInd = i;
        }
        rightMax[i]=maxInd;
    }

    // swap
    for (int i = 0; i < n; i++)
    {
        if (digits[i]<digits[rightMax[i]])
        {
            swap(digits[i],digits[rightMax[i]]);
            break;
        }
    }

    // add digits back to num
    string numStr = "";
    for (int i = 0; i < n; i++)
    {
        numStr += to_string(digits[i]);
    }
    int ans = stoi(numStr);
    return ans;
}

int main()
{
    int num = 2736;
    cout << "\nThe maximum number that can be formed after swapping atmost 2 digits: " << maximumSwap(num);

    return 0;
}