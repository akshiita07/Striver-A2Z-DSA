#include <bits/stdc++.h>
using namespace std;

int minMaxDifference(int num)
{
    // to obtain max no: remap smallest digit to 9
    // to obtain min no: remap largest digit to 0
    // return diff bw max & min no
    string strNum = to_string(num);
    int n = strNum.length();
    string maxNum = strNum;
    string minNum = strNum;
    char digitForMax = strNum[0];
    char digitForMin = strNum[0];
    // find first digit to be replaced
    int i = 0;
    while (strNum[i] == '9')
    {
        i++;
    }
    digitForMax = strNum[i];
    digitForMin = strNum[0];
    cout << "\nFound Digit to be replaced for max: " << digitForMax;
    cout << "\nFound Digit to be replaced for min: " << digitForMin;
    // remap all occurrences of digitForMax to 9 to get largest number
    for (int i = 0; i < n; i++)
    {
        if (maxNum[i] == digitForMax)
        {
            maxNum[i] = '9';
        }
    }
    cout << "\nLargest Number formed: " << maxNum;
    // remap all occurrences of digitForMin to 0 to get smallest number
    for (int i = 0; i < n; i++)
    {
        if (minNum[i] == digitForMin)
        {
            minNum[i] = '0';
        }
    }
    cout << "\nSmallest Number formed: " << minNum;
    // return differnce after converting string to int
    return stoi(maxNum) - stoi(minNum);
}

int main()
{
    int num1 = 11891;
    cout << "\nMaximum Difference by Remapping a Digit: " << minMaxDifference(num1);
    int num2 = 99189;
    cout << "\nMaximum Difference by Remapping a Digit: " << minMaxDifference(num2);

    return 0;
}