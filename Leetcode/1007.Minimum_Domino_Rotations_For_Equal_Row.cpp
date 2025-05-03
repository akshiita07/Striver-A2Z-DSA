#include <bits/stdc++.h>
using namespace std;

// top & bottom halves of ith domino
// domino: 2 numbers from 1 to 6
// rotate operation on ith domino: swaps tops[i] and bottoms[i] position
// return min no of operations so that either all top dominos have same values or all botttom dominos have same value
// else return -1 if not possible

int isPossible(vector<int> &tops, vector<int> &bottoms, int num)
{
    int n = tops.size();
    // count no of rotations for both top & bottom:
    int rotationsTop = 0;
    int rotationsBottom = 0;
    for (int i = 0; i < n; i++)
    {
        // check if both top & bottom have same value:
        if (tops[i] != num && bottoms[i] != num)
        {
            // not possible:
            return -1;
        }
        if (tops[i] != num)
        {
            // rotate top
            rotationsTop++;
        }
        if (bottoms[i] != num)
        {
            // rotate bottoms
            rotationsBottom++;
        }
    }
    // check min no of rotations:
    return min(rotationsTop, rotationsBottom);
}

int brute_force(vector<int> &tops, vector<int> &bottoms)
{
    int n = tops.size();
    int minRotations = INT_MAX;
    // check for all values from 1 to 6:
    for (int num = 1; num <= 6; num++)
    {
        int check = isPossible(tops, bottoms, num);
        if (check != -1)
        {
            // ie possible:
            minRotations = min(minRotations, check);
        }
    }
    if (minRotations == INT_MAX)
    {
        return -1;
    }
    return minRotations;
}

int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    // first check only tops[0] and bottoms[0] values, if they dont match then return -1
    // check tops[0]:
    int ans = isPossible(tops, bottoms, tops[0]);
    if (ans != -1)
    {
        return ans;
    }
    if (tops[0] != bottoms[0])
    {
        return isPossible(tops, bottoms, bottoms[0]);
    }
    return -1;
}

int main()
{
    vector<int> tops = {2, 1, 2, 4, 2, 2};
    vector<int> bottoms = {5, 2, 6, 2, 3, 2};
    cout << "\nbrute_force min no of operations= " << brute_force(tops, bottoms);
    cout << "\n min no of operations= " << minDominoRotations(tops, bottoms);

    return 0;
}