class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        int start = 1;
        // loop for n times:
        for (int i = 0; i < n; i++)
        {
            // push current no:
            ans.push_back(start);
            if (start * 10 <= n)
            {
                // the next lexicographic no is obtained on *10
                start = start * 10;
            }
            else
            {
                // if we exceeded n then backtrack:
                if (start >= n)
                {
                    start = start / 10;
                }
                start++;
                while (start % 10 == 0)
                {
                    start /= 10;
                }
            }
        }
        return ans;
    }
};