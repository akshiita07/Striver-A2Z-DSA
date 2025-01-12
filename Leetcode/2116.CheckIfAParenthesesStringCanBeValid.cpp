#include <bits/stdc++.h>
using namespace std;

bool canBeValid(string s, string locked)
{
    // locked consists of 0s & 1s
    // If locked[i] is '1', you cannot change s[i].
    // But if locked[i] is '0', you can change s[i] to either '(' or ')'
    // Return true if you can make s a valid parentheses string ie () or (AB) or (A)

    // 1. odd length string can never be valid:
    if (s.length() % 2 != 0)
    {
        return false;
    }

    // 2. left to right pass
    int open = 0;
    int unlocked = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (locked[i] == '0')
        {
            unlocked++;
        }
        else if (s[i] == '(')
        {
            open++;
        }
        else
        {
            // s[i]==')'
            // balance ) with a (
            if (open > 0)
            {
                open--;
            }
            else if (unlocked > 0)
            {
                unlocked--;
            }
            else
            {
                // if still remaining:
                return false;
            }
        }
    }

    // 3. right to left pass
    int closed = 0;
    unlocked = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (locked[i] == '0')
        {
            unlocked++;
        }
        else if (s[i] == ')')
        {
            closed++;
        }
        else
        {
            // s[i]=='('
            // balance ( with a )
            if (closed > 0)
            {
                closed--;
            }
            else if (unlocked > 0)
            {
                unlocked--;
            }
            else
            {
                // if still remaining:
                return false;
            }
        }
    }

    return true;
}

int main()
{
    string s = "))()))";
    string locked = "010100";
    cout << "\nCan a valid s string be formed: " << canBeValid(s, locked);

    return 0;
}