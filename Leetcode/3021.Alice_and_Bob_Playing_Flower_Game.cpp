#include <bits/stdc++.h>
using namespace std;

long long brute_force(int n, int m)
{
    // 2 lanes of flowers in between alice & bob
    // 1st lane has x flowers
    // 2nd lane has y flowers
    // each turn: player chooses a side of the lane-> picks flower from that
    // lane-> if no flowers left then that player wins compute number of
    // possible pairs (x,y) such that Alice wins the game, range of x=[1,n],
    // range of y=[1,m] take x from 1 to n and take y from 1 to m such that
    // both x & y have different parities
    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((i % 2 == 0 && j % 2 != 0) || (i % 2 != 0 && j % 2 == 0))
            {
                cnt++;
            }
        }
    }
    return cnt;
}

long long flowerGame(int n, int m)
{
    // 2 lanes of flowers in between alice & bob
    // 1st lane has x flowers
    // 2nd lane has y flowers
    // each turn: player chooses a side of the lane-> picks flower from that
    // lane-> if no flowers left then that player wins compute number of
    // possible pairs (x,y) such that Alice wins the game, range of x=[1,n],
    // range of y=[1,m] take x from 1 to n and take y from 1 to m such that
    // both x & y have different parities
    int oddN = (n + 1) / 2;
    int evenN = n / 2;
    int oddM = (m + 1) / 2;
    int evenM = m / 2;
    long long cnt = (1LL * oddN * evenM) + (1LL * evenN * oddM);
    return cnt;
}

int main()
{
    int n = 3;
    int m = 2;
    cout << flowerGame(n, m);

    return 0;
}