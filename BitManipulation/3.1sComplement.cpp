#include <bits/stdc++.h>
using namespace std;

vector<int> toBinary(int n)
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
    cout << "The binary form is: " << endl;
    for (auto it : binary)
    {
        cout << it;
    }
    return binary;
}

void OnesComplement(int n)
{
    vector<int> bin = toBinary(n);
    for (int i = 0; i < bin.size(); i++)
    {
        if (bin[i] == 0)
        {
            bin[i] = 1;
        }
        else
        {
            bin[i] = 0;
        }
    }
    cout << "The 1s complement is: " << endl;
    for (auto it : bin)
    {
        cout << it;
    }
}

int main()
{
    int n = 13;
    cout << endl;
    OnesComplement(n);

    return 0;
}