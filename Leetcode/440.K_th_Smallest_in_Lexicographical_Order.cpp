// TLE:
int findKthNumber(int n, int k)
{
    vector<int> lexicArr;

    int start = 1;
    for (int i = 0; i < n; i++)
    {
        lexicArr.push_back(start);
        // check if can be multiplied by 10:
        if (start * 10 <= n)
        {
            start = start * 10;
        }
        else
        {
            // exceed so backtrack
            if (start >= n)
            {
                start = start / 10;
            }
            start++;
            // remove trailing zeroes
            while (start % 10 == 0)
            {
                start = start / 10;
            }
        }
    }

    cout << "\nPrininting lexicographic array ";
    for (auto it : lexicArr)
    {
        cout << it << " ";
    }
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans = lexicArr[i];
    }
    return ans;
}

long countSteps(long prefix, long n)
{
    long steps = 0;
    long first = prefix;
    long last = prefix;

    while (first <= n)
    {
        steps += min(n + 1, last + 1) - first;
        first *= 10;
        last = last * 10 + 9;
    }

    return steps;
}

int findKthNumber(int n, int k)
{
    long current = 1;
    k = k - 1; // We are looking for the k-th number, so adjust to zero-indexing.

    while (k > 0)
    {
        long steps = countSteps(current, n);
        if (steps <= k)
        {
            // If the subtree rooted at 'current' has fewer than or exactly
            // 'k' numbers, we skip all of them and move to the next number
            // at the same level.
            k -= steps;
            current++;
        }
        else
        {
            // If the subtree has more than 'k' numbers, we go down one
            // level (i.e., expand the current prefix).
            current *= 10;
            k--; // Moving down to the next level counts as one step.
        }
    }

    return current;
}
