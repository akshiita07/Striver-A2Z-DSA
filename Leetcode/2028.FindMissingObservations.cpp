#include <bits/stdc++.h>
using namespace std;

vector<int> missingRolls(vector<int> &rolls, int mean, int n)
{
    // have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6
    // n of the observations went missing
    // you only have the observations of m rolls
    // have calculated the average value of the n + m rolls
    // Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean
    vector<int> ans;
    int m = rolls.size();
    int totalObservations = m + n;
    int initialSum = 0;
    for (auto it : rolls)
    {
        initialSum += it;
    }
    cout << "\nThe initial sum of rolls gives: " << initialSum;

    int remainingSum = (mean * totalObservations) - initialSum;
    cout << "\nThe remaining sum reqd for missing rolls: " << remainingSum;

    // check is it possible to divide remaining numbers from 1 to 6?
    if (remainingSum < n || remainingSum > 6 * n)
    {
        // if it is smaller than min no of elem reqd in missing array
        // or if it is greater if 6 times also exceeds it
        return {};
    }
    // now we need to divide this remaining sum into n halves such that all nos between 1 to 6:
    int baseVal = remainingSum / n;
    int extraVal = remainingSum % n;
    for (int i = 0; i < n; i++)
    {
        if (i < extraVal)
        {
            // until we have extra elements keep on adding them by 1
            ans.push_back(baseVal+extraVal);
        }
        else
        {
            // distribute remaining even numbers properly
            ans.push_back(baseVal);
        }
    }

    cout << "\nThe missing rolls are: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return ans;
}

int main()
{
    vector<int> rolls = {1, 5, 6};
    int mean = 3;
    int n = 4;
    // Output: [2,3,2,2]
    missingRolls(rolls, mean, n);

    return 0;
}