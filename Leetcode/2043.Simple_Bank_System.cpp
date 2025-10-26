#include <bits/stdc++.h>
using namespace std;

class Bank
{
public:
    // successfull transaction: acc numb between 1 to n, amt of money
    // withdrawn/transferred<=balance
    vector<long long> balanceArray;

    Bank(vector<long long> &balance)
    {
        // acc no must be between 1 to n
        // balance[i] denotes balance of (i+1) account
        int n = balance.size();
        balanceArray = balance;
    }

    bool transfer(int account1, int account2, long long money)
    {
        // transfer money from acc1 to acc2 & return true for successful else
        // false
        int n = balanceArray.size();
        if (!(account1 >= 1 && account1 <= n) ||
            !(account2 >= 1 && account2 <= n))
        {
            cout << "\nNot in range so false\n";
            return false;
            // acc not between 1 to n so unsuceessful
        }
        // check balance>=money:
        if ((account1 - 1) < n && (account2 - 1) < n)
        {
            if (!(balanceArray[account1 - 1] >= money))
            {
                return false;
            }
            // transfer money:
            balanceArray[account1 - 1] -= money;
            balanceArray[account2 - 1] += money;
        }
        return true;
    }

    bool deposit(int account, long long money)
    {
        // deposit money in acc & return true for successful else false
        // transfer money from acc1 to acc2 & return true for successful else
        // false
        int n = balanceArray.size();
        if (!(account >= 1 && account <= n))
        {
            cout << "\nNot in range so false\n";
            return false;
            // acc not between 1 to n so unsuceessful
        }
        // check balance>=money:
        balanceArray[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        // withdraw money from acc & return true for successful else false
        // transfer money from acc1 to acc2 & return true for successful else
        // false
        int n = balanceArray.size();
        if (!(account >= 1 && account <= n))
        {
            cout << "\nNot in range so false\n";
            return false;
            // acc not between 1 to n so unsuceessful
        }
        // check balance>=money:
        if ((account - 1) < n)
        {
            if (!(balanceArray[account - 1] >= money))
            {
                return false;
            }
            balanceArray[account - 1] -= money;
        }
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

int main()
{

    return 0;
}