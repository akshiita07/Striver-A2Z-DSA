#include <bits/stdc++.h>
using namespace std;

int maxDiff(int num)
{
    // select digit x from num
    // select digit y from num for maxNum:y=9 & for minNum:y=1
    // replace all x with y in num to get maxNum and minNum
    // return maxNum - minNum
    string strNum = to_string(num);
    int n = strNum.length();
    int i = 0;
    char x = strNum[i];
    while (x == '9')
    {
        x = strNum[i + 1];
        i++;
    }
    // for maxNum:
    string a = strNum;
    char y = '9';
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            a[i] = y;
        }
    }
    // for minNum:
    string b = strNum;
    i = 0;
    x = strNum[i];
    while (x == '1' || x == '0')
    {
        x = strNum[i + 1];
        i++;
    }
    if (i == 0)
    {
        // at 1st index only so replace by 1 else by 0
        y = '1';
    }
    else
    {
        y = '0';
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == x)
        {
            b[i] = y;
        }
    }
    return stoi(a) - stoi(b);
}

int main()
{
    int num1 = 555;
    cout << "\nMax Difference: " << maxDiff(num1); // 888
    int num2 = 123456;
    cout << "\nMax Difference: " << maxDiff(num2); // 820000
    int num3 = 9124;
    cout << "\nMax Difference: " << maxDiff(num3); // 8800
    return 0;
}