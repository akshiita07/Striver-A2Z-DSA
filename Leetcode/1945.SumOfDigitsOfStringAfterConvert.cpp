#include <bits/stdc++.h>
using namespace std;

// TIME: O(n*k)->2 loops
// SPACE: O()
int getLucky(string s, int k)
{
    // s: lowecase english letters
    // convert s to an integer by replacing each letter with its position in the alphabet:'a' with 1, 'b' with 2, ..., 'z' with 26

    // convert char to ascii a:97 so subtract some value with ascii
    string convertedString;
    for (int i = 0; i < s.length(); i++)
    {
        convertedString += to_string(s[i] - 'a' + 1);
    }
    cout << "After converting to numbers: " << convertedString << endl;

    // transform the integer by replacing it with the sum of its digits
    int ans;
    while (k > 0)
    {
        ans = 0;
        for (int i = 0; i < convertedString.length(); i++)
        {
            ans += (convertedString[i] - '0');
        }
        cout << "\nAfter 1 iteration: " << ans;
        // change convertedString
        convertedString = to_string(ans);
        k--;
    }
    // Repeat the transform operation k times in total
    return ans;
}

int main()
{
    string s = "zbax";
    int k = 2;
    cout << "\nThe string " << s << " after " << k << " no of transforms results in: " << getLucky(s, k);

    return 0;
}