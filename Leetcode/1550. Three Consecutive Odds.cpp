class Solution
{
public:
    bool brute_Force(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 != 0)
            {
                // it is odd check next 2:
                if (i < n && (i + 1) < n && (i + 2) < n)
                {
                    if (arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i <= n - 2; i++)
        {
            if (i < n && (i + 1) < n && (i + 2) < n && arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0)
            {
                return true;
            }
        }
        return false;
    }
};