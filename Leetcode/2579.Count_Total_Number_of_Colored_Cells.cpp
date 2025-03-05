#include <bits/stdc++.h>
using namespace std;

long long coloredCells(int n)
{
    // at n=1: color 1 cell
    // at n=2: color cells touching prev cell ie 4 more added : up,down,left right
    // at n=3: color cells touching prev cells ie 8 more added : up,down,left right, 4 diagonal
    // ie series: 1,4,8,12,_ _ _
    // so minutes: 1,1+4,1+4+8,1+4+8+12,- -
    // ie 1,5,13,25,_ _ _
    // Total cells= n^2 +(n-1)^2

    long long N = n;
    return 1LL * N * N + (N - 1) * (N - 1);
}

int main()
{
    int n = 5;
    cout << "\nTotal no of colored cells= " << coloredCells(n) << endl;

    return 0;
}