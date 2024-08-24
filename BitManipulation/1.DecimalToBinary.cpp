#include <bits/stdc++.h>
using namespace std;

// TIME: O(log2(n))->dividing by 2 each time
// SPACE: O(log2(n))->storing remainders
void toBinary(int n)
{
    vector<int> binary;
    while (n != 1)
    {
        int remain = n % 2;
        binary.push_back(remain);
        n = n / 2;
    }
    // also at the end push this 1
    binary.push_back(1);
    reverse(binary.begin(), binary.end());
    for (auto it : binary)
    {
        cout << it;
    }
}

int main()
{
    int n1 = 7;
    toBinary(n1);
    cout<<endl;
    int n2 = 13;
    toBinary(n2);

    return 0;
}