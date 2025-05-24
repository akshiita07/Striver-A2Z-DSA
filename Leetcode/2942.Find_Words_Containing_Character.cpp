class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++)
        {
            // now for each word traverse till end to find character x:
            for (int j = 0; j < words[i].length(); j++)
            {
                if (words[i][j] == x)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};