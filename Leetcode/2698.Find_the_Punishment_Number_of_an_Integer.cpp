#include <bits/stdc++.h>
using namespace std;

// check if valid:
bool(isValidPartition(string squareString, int number, int index = 0, int currentSum = 0))
{
    // if end reached:base case:
    if (index == squareString.length())
    {
        if (currentSum == number)
        {
            return true;
        }
    }

    int sum = 0;
    // check partitions of square:
    for (int i = index; i < squareString.length(); i++)
    {
        // convert substring to integer:
        sum = (sum * 10) + (squareString[i] - '0');
        if (sum > number)
        {
            break;
        }
        // increase index & add to sum:
        if (isValidPartition(squareString, number, i + 1, currentSum + sum))
        {
            return true;
        }
    }
    return false;
}

int punishmentNumber(int n)
{
    // punishment number of n: sum of the squares of all integers i st: 1 <= i <= n
    // decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        int number = i;
        int square = i * i;
        string squareString = to_string(square);
        // check if SUM of partitions==number then count+=i*i
        if (isValidPartition(squareString, number))
        {
            count += square;
        }
    }
    return count;
}

int main()
{
    int n = 10;
    cout << "\nPunishment is: << punishmentNumber(n) << endl;
        return 0;
}