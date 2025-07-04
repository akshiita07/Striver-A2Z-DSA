#include <bits/stdc++.h>
using namespace std;

char kthCharacter(long long k, vector<int> &operations)
{
    // initial string word = "a"
    // if operations[i]==0: append copy of word to itself
    // if operations[i]==1: append the next character in english alphabet to the end of word
    // return this kth character of word
    vector<long long> length = {1}; // start with "a" so length=1
    for (auto it : operations)
    {
        // calculate length of string after each opertaion:
        long long prev = length.back();
        length.push_back(min(prev * 2, k)); // length doubles eacg time but we only need up to kth character
    }

    // Start from end of operations and go backward
    int shift = 0;
    for (int i = operations.size(); i > 0; i--)
    {
        // get operation to perform
        int op = operations[i - 1];
        // get length of string before this operation
        long long prevLen = length[i - 1];
        if (k > prevLen)
        {
            // check if k is in the appended half
            if (op == 0)
            {
                // go back prev length
                k -= prevLen;
            }
            else if (op == 1)
            {
                // shift by 1 character
                k -= prevLen;
                shift += 1;
            }
        }
        else
        {
            // k is in the original half
            continue;
        }
    }

    // Original string was "a", so only one character
    // shift it 'shift' times (with wrap-around after 'z')
    return 'a' + (shift % 26);
}

int main()
{
    long long k = 10;
    vector<int> operations = {0, 1, 0, 1};
    cout << "\nKth character is: " << kthCharacter(k, operations);

    return 0;
}