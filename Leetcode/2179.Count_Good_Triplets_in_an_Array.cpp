#include <bits/stdc++.h>
using namespace std;

long long brute_force(vector<int> &nums1, vector<int> &nums2)
{
    // Return the total number of good triplets
    // Good Triplet set of 3 values (x,y,z) present in increasing order in both nums1 and nums2 st pos1x < pos1y < pos1z & pos2x < pos2y < pos2z
    int n = nums1.size(); //==nums2.size()
    // fix y and count how many x exist st pos1[x]<pos1[y] and pos2[x]<pos2[y]
    // fix y and count how many z exist st pos1[y]<pos1[z] and pos2[y]<pos2[z]

    // position maps ie nums1[i] is at which index:
    vector<int> pos1(n);
    vector<int> pos2(n);
    for (int i = 0; i < n; i++)
    {
        pos1[nums1[i]] = i;
        pos2[nums2[i]] = i;
    }

    // a mapping array where mapped[i] will tell position of nums1[i] in nums2 array
    vector<int> mapped(n);
    for (int i = 0; i < n; i++)
    {
        mapped[i] = pos2[nums1[i]];
    }

    // count elements before i having mapped[j]<mapped[i]
    vector<int> left(n, 0);
    set<int> seenLeft;
    for (int i = 0; i < n; i++)
    {
        for (auto it : seenLeft)
        {
            if (it < mapped[i])
            {
                left[i]++;
            }
        }
        seenLeft.insert(mapped[i]);
    }

    // count elements after i having mapped[j]>mapped[i]
    vector<int> right(n, 0);
    set<int> seenRight;
    for (int i = n - 1; i >= 0; i--)
    {
        for (auto it : seenRight)
        {
            if (it > mapped[i])
            {
                right[i]++;
            }
        }
        seenRight.insert(mapped[i]);
    }

    // total ans:
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += 1LL * left[i] * right[i];
    }
    return ans;
}

// optimal:
class FenwickTree
{
public:
    vector<int> bit;
    int n;

    FenwickTree(int size)
    {
        n = size + 2; // a bit extra
        bit.assign(n, 0);
    }

    void update(int idx, int val)
    {
        idx++; // 1-based indexing
        while (idx < n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx)
    {
        idx++; // 1-based indexing
        int sum = 0;
        while (idx > 0)
        {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    int range(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();

    vector<int> pos2(n);
    for (int i = 0; i < n; i++)
    {
        pos2[nums2[i]] = i;
    }

    vector<int> mapped(n);
    for (int i = 0; i < n; i++)
    {
        mapped[i] = pos2[nums1[i]];
    }

    vector<int> left(n), right(n);
    FenwickTree bitLeft(n), bitRight(n);

    // LEFT count
    for (int i = 0; i < n; i++)
    {
        left[i] = bitLeft.query(mapped[i] - 1);
        bitLeft.update(mapped[i], 1);
    }

    // RIGHT count
    for (int i = n - 1; i >= 0; i--)
    {
        right[i] = bitRight.query(n - 1) - bitRight.query(mapped[i]);
        bitRight.update(mapped[i], 1);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += 1LL * left[i] * right[i];
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {4, 0, 1, 3, 2};
    vector<int> nums2 = {4, 1, 0, 2, 3};
    cout << "\nGood Triplets: " << goodTriplets(nums1, nums2);

    return 0;
}