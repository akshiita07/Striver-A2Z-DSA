// #include <bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n)
{
    // repeatedly divide by 3 until we get 1
    while (n != 1 && n > 0)
    {
        if (n % 3 != 0)
        {
            return false;
        }
        n = n / 3;
    }
    if (n == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    int n = 27;
    cout << "\nAns= " << isPowerOfThree(n);

    return 0;
}