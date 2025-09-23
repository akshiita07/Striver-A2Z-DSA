#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        // 2 pointer approach:
        int i = 0;
        int j = 0;
        int n1 = version1.size();
        int n2 = version2.size();
        // until characters left:
        while (i < n1 || j < n2)
        {
            // get versions:
            int num1 = 0;
            int num2 = 0;
            // extract revision number after . from version no:
            while (i < n1 && version1[i] != '.')
            {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < n2 && version2[j] != '.')
            {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            // compare:
            if (num1 < num2)
            {
                return -1;
            }
            else if (num1 > num2)
            {
                return 1;
            }
            // increment pointers:
            i++;
            j++;
        }
        return 0; // else
    }
};

int main()
{

    return 0;
}