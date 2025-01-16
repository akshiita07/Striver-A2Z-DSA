#include <bits/stdc++.h>
using namespace std;

bool checkIfInNonDecOrder(vector<int> &boxes, int n, int k)
{
    if (k == 1)
    {
        vector<int> copy = boxes;
        sort(copy.begin(), copy.end());
        for (int i = 0; i < n; i++)
        {
            if (copy[i] != boxes[i])
            {
                return false;
            }
        }
    }
    // if k>1 then always possible to sort so true:
    return true;
}

int main()
{
    int t;
    cin >> t; // no of test cases

    // run for all test cases:
    for (int tc = 1; tc <= t; tc++)
    {
        int n; // number of boxes
        int k; // length of the maximum reverse
        cin >> n >> k;
        vector<int> boxes(n);
        for (int i = 0; i < n; i++)
        {
            cin >> boxes[i]; // number written on each box
        }

        bool is_possible = checkIfInNonDecOrder(boxes, n, k);

        if (is_possible == true)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}