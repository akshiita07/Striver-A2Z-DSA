#include <bits/stdc++.h>
using namespace std;

bool canChange(string start, string target)
{
    // piece 'L' can move to the left only if there is a blank space directly to its left,
    // piece 'R' can move to the right only if there is a blank space directly to its right.
    // order of L and R must be same after _ are ignored to change string:
    string start_withoutBlanks = "";
    string target_withoutBlanks = "";
    for (int i = 0; i < start.length(); i++)
    {
        if (start[i] != '_')
        {
            start_withoutBlanks += start[i];
        }
    }
    for (int i = 0; i < target.length(); i++)
    {
        if (target[i] != '_')
        {
            target_withoutBlanks += target[i];
        }
    }
    // now check if both equal:
    if (start_withoutBlanks != target_withoutBlanks)
    {
        return false;
    }

    // if equal then validate movements wrt blanks:
    // 2 pointers to traverse:
    int i = 0;
    int j = 0;
    int n = start.length();
    while (i < n && j < n)
    {
        // skip all blanks to reach a character
        while (i < n && start[i] == '_')
        {
            i++;
        }
        while (j < n && target[j] == '_')
        {
            j++;
        }
        // if both ptrs at valid positions then:
        if (i < n && j < n)
        {
            // L can move only to left so i>j
            if (start[i] == 'L' && i < j)
            {
                return false;
            }
            // R can move only to rigt so i<j
            if (start[i] == 'R' && i > j)
            {
                return false;
            }
            i++;
            j++;
        }
    }
    // else:
    return true;
}

int main()
{
    string start = "_L__R__R_";
    string target = "L______RR";
    cout << "\nCan start=target string?: " << canChange(start, target);
    return 0;
}