// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int maxBottlesDrunk(int numBottles, int numExchange)
{
    int drink = numBottles;
    int empty = numBottles;

    while (empty >= numExchange)
    {
        // do only ONE exchange:
        empty -= numExchange;
        numExchange++;
        drink++;
        empty++;
    }
    return drink;
}

int main()
{
    int numBottles = 13;
    int numExchange = 6;
    cout << "\nMaxm bottles that can be drunk: " << maxBottlesDrunk(numBottles, numExchange);

    return 0;
}