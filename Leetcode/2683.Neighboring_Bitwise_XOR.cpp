#include <bits/stdc++.h>
using namespace std;

bool doesValidArrayExist(vector<int> &derived)
{
    int n = derived.size();
    // derived= adjacent XOR of original array
    // derived[i] = original[i] ⊕ original[i + 1]
    // but for last element: derived[i] = original[i] ⊕ original[0]
    // does a binary array (0/1s) original exists?
    // A⊕A=0    same bits 0
    // A⊕0=A    with 0 get same bit
    int xorDerived = 0;
    for (int i = 0; i < n; i++)
    {
        xorDerived = (xorDerived ^ derived[i]);
    }
    if (xorDerived == 1)
    {
        return false;
    }
    return true;
}

int main()
{
    vector<int> derived = {1, 1, 0};
    cout << "\nDoes original array exists: " << doesValidArrayExist(derived);

    return 0;
}