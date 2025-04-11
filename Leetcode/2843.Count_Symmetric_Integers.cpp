#include <bits/stdc++.h>
using namespace std;

int countSymmetricIntegers(int low, int high)
{
    // integer x containing 2*n digits is symmetric if sum of first n digits of x=sum of last n digits of x
    // return no of symmetric integers in the range [low, high]
    int count = 0;
    for (int i = low; i <= high; i++)
    {
        // convert number to string
        string s = to_string(i);
        // break into 2 equal haves
        string first_half = s.substr(0, s.length() / 2);
        string second_half = s.substr(s.length() / 2);
        // both must have equal length:
        if (first_half.length() == second_half.length())
        {
            // check sum of 1st half=sum of 2nd half then cnt++
            int sum_firstHalf = 0;
            int sum_secondHalf = 0;

            for (int j = 0; j < first_half.length(); j++)
            {
                // -'0' to convert char to int
                sum_firstHalf += (first_half[j] - '0');
                sum_secondHalf += (second_half[j] - '0');
            }
            if (sum_firstHalf == sum_secondHalf)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int low = 1;
    int high = 100;
    cout << "\n no of symmetric integers=" << countSymmetricIntegers(low, high);

    return 0;
}