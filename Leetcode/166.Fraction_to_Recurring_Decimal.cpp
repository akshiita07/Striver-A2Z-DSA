#include <bits/stdc++.h>
using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
    if (numerator == 0)
    {
        return "0";
    }
    string ans;
    // if any of num XOR den are less than 0 then ans will be -ve:
    if ((numerator < 0) ^ (denominator < 0))
    {
        ans += "-";
    }
    // convert both numerator & denominator to long long:
    long long num = abs((long long)numerator);
    long long den = abs((long long)denominator);
    // add quotient:
    long long fraction = num / den;
    ans += to_string(fraction);
    long long remainder = num % den;
    if (remainder == 0)
    {
        // if fully divisble then return ans
        return ans;
    }
    // check if repeating remainder then enclose in ():
    ans += ".";                                 // for decimal part
    unordered_map<long long, int> remainderMap; // store remainder & the position in ans string
    while (remainder != 0)
    {
        if (remainderMap.count(remainder))
        {
            ans.insert(remainderMap[remainder], "(");
            ans += ")";
            break;
        }
        remainderMap[remainder] = ans.size();
        remainder *= 10;
        ans += to_string(remainder / den);
        remainder = remainder % den;
    }
    return ans;
}

int main()
{

    return 0;
}