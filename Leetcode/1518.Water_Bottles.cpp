#include <bits/stdc++.h>
using namespace std;

int numWaterBottles(int numBottles, int numExchange)
{
    // drink numBottles first
    // check how many u can exchange
    // drink them
    // exchange
    // count how many u can drink
    int drink = numBottles;
    cout << "\nInitially drank " << drink << " no of bottles";
    int canBeExchanged = numBottles / numExchange;
    int remainingBottles = numBottles - (canBeExchanged * numExchange);
    cout << "\nRemaining bottles that cannot be exchanged " << remainingBottles;
    while (canBeExchanged > 0)
    {
        cout << "\nCan be exchanged: " << canBeExchanged;
        drink += canBeExchanged;
        cout << "\nAfter exchange i drank: " << drink << " no of extra bottles";
        numBottles = remainingBottles + canBeExchanged;
        canBeExchanged = numBottles / numExchange;
        remainingBottles = numBottles - (canBeExchanged * numExchange);
    }
    return drink;
}

int main()
{

    return 0;
}