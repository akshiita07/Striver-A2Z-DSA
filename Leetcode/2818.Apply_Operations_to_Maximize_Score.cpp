#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// to find prime score: ie total no of distinct prime factors of a number
int findPrimeScore(int num)
{
    int ans = 0;
    // iterate from 2 to sqrt(num)
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            // number i is a factor of num
            ans++;
            // as we want distinct prime factors we will remove all
            // occurrences of number i from num by dividing it
            while (num % i == 0)
            {
                num /= i;
            }
        }
    }
    if (num > 1)
    {
        // if num itself is also a prime factor then count it also
        ans++;
    }
    return ans;
}

int findPowerMod(long long base, long long exp, int mod)
{
    // to avoid overflows use long long
    long long ans = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return ans;
}

int maximumScore(vector<int> &nums, int k)
{
    int n = nums.size();
    long long score = 1;
    // apply operation ATMOST k times (k or less)
    // choose non empty subarray that is NOT previously chosen then select
    // element x with HIGHEST PRIME SCORE AT SMALLEST index then multiply
    // score by this element x prime score of an integer x is equal to the
    // number of distinct prime factors of x Return the maximum possible
    // score modulo 10^9 + 7
    vector<int> primeScores(n);
    for (int i = 0; i < n; i++)
    {
        primeScores[i] = findPrimeScore(nums[i]);
    }

    // using monotonic stack to find nearest left & right boundaries:
    vector<int> left(n, -1);
    vector<int> right(n, n);
    stack<int> st;
    // calculate left boundaries
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && primeScores[st.top()] < primeScores[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            left[i] = st.top();
        }
        st.push(i);
    }
    // clear stack to calculate right boundaries
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && primeScores[st.top()] <= primeScores[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            right[i] = st.top();
        }
        st.push(i);
    }
    // compute no of valid ranges:
    vector<pair<int, int>> elements;
    vector<long long> count(n);
    for (int i = 0; i < n; i++)
    {
        count[i] = 1LL * (i - left[i]) * (right[i] - i);
        elements.push_back({nums[i], i});
    }
    // sort elements in descending order:
    sort(elements.begin(), elements.end(),
         [](pair<int, int> &a, pair<int, int> &b)
         {
             return a.first > b.first;
         });

    for (auto element : elements)
    {
        int i = element.second; // index
        int ans = min(count[i], (long long)k);
        score = (1LL * score * findPowerMod(nums[i], ans, mod)) % mod;
        k -= ans;
        if (k == 0)
        {
            break;
        }
    }

    return score;
}

int main()
{
    vector<int> nums = {8, 3, 9, 3, 8};
    int k = 2;
    cout << "\nMaximum score: " << maximumScore(nums, k);

    return 0;
}