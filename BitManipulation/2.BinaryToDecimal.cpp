#include <bits/stdc++.h>
using namespace std;

// TIME: O(len(str))
// SPACE: O(1)
void toDecimal(string n)
{
    int decimal = 0;
    int count = 0;
    // traverse backwards
    for (int i = n.length() - 1; i >= 0; i--)
    {
        if (n[i] == '1')
        {
            // that character is 1:
            decimal += 1 * pow(2, count);
        }
        count++;
    }
    cout << decimal;
}

int main()
{
    string n1 = "111";
    toDecimal(n1);
    cout << endl;
    string n2 = "1101";
    toDecimal(n2);

    return 0;
}