class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // get all letters of maganize:
        unordered_map<char, int> hashMap;
        for (int i = 0; i < magazine.length(); i++)
        {
            hashMap[magazine[i]] += 1;
        }
        // get all letters of ransom notes:
        for (int i = 0; i < ransomNote.length(); i++)
        {
            // now check if magaz contains all ransom
            if (hashMap[ransomNote[i]] > 0)
            {

                hashMap[ransomNote[i]] -= 1; // reduce its value also
            }
            else
            {
                // its value is 0:
                return false;
            }
        }
        return true;
    }
};