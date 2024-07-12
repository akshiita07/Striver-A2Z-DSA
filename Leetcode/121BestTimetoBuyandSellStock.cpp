#include <bits/stdc++.h>
using namespace std;

// brute force
int maxProfit_Brute(int prices[], int n)
{
    if (n <= 1)
    {
        return 0; // if only 1 element present then profit will be 0
    }

    int profit;
    int maxProfit = INT_MIN;
    int sellStock, buyStock;

    // first find when  to sell- DO NOT CHOOSE FIRST
    for (int i = 1; i < n; i++)
    {
        sellStock = i; // when price[i] is max but buy is earlier then sell
        for (int j = 0; j < i; j++)
        {
            profit = prices[i] - prices[j];
            // when to buy
            if (profit >= 0)
            {
                if (profit >= maxProfit)
                {
                    maxProfit = profit;
                    buyStock = j;
                }
            }
        }
    }
    cout << "Buy day " << buyStock << " Price- " << prices[buyStock] << endl;
    cout << "Sell day " << sellStock << " Price- " << prices[sellStock] << endl;

    if (maxProfit > 0)
    {
        return maxProfit;
    }
    return 0;
}

// Optimal
int maxProfit_Optimal(int prices[], int n)
{
    if (n <= 1)
    {
        return 0; // if only 1 element present then profit will be 0
    }

    int profit = 0;
    int maxProfit = 0;
    int sellStock;
    int buyStock = 0;

    // first find when  to sell- DO NOT CHOOSE FIRST
    for (int i = 1; i < n; i++)
    {
        sellStock = i;
        profit = prices[sellStock] - prices[buyStock];
        if(profit>=maxProfit){
            maxProfit=profit;
        }
        if(prices[i]<prices[buyStock]){
            buyStock=i;
        };
    }
    cout << "Buy day " << buyStock << " Price- " << prices[buyStock] << endl;
    cout << "Sell day " << sellStock << " Price- " << prices[sellStock] << endl;

    return maxProfit;
}

int main()
{
    // int prices[] = {7, 1, 5, 3, 6, 4};
    // int prices[] = {2,1,2,1,0,1,2};
    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    // int prices[] = {2, 4, 1};
    int n = sizeof(prices) / sizeof(prices[0]);
    // cout << "\nThe max profit is: " << maxProfit_Brute(prices, n) << endl;
    cout << "\nThe max profit is: " << maxProfit_Optimal(prices, n) << endl;

    return 0;
}