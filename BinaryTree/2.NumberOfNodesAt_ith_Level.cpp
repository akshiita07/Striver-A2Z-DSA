#include <bits/stdc++.h>
using namespace std;

int countNodes(int i)
{
    return pow(2, i - 1);
}

int main()
{
    int i = 5;
    cout << "The no of nodes at " << i << " level are: " << countNodes(i);

    return 0;
}