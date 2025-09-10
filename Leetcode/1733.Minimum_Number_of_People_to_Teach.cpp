#include <bits/stdc++.h>
using namespace std;

int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
{
    // m users
    // 1 to n languages
    // 2 ppl can communicate if they know a common language
    // languages[i] is the set of languages the i​​​​​​th​​​​ user knows
    // friendships[i] = [u​​​​​​i​​​, v​​​​​​i]:friendship bw users ui & vi
    // choose a language & teach such that all friends can communicate
    // Return the minimum number of users you need to teach
    int m = languages.size();
    // for each user create a set of languages known:
    vector<unordered_set<int>> langKnown(m + 1);
    for (int i = 0; i < m; i++)
    {
        for (auto it : languages[i])
        {
            langKnown[i + 1].insert(it);
        }
    }
    // find friends who dont have any common language:
    vector<pair<int, int>> noCommonLang;
    for (auto it : friendships)
    {
        int person1 = it[0];
        int person2 = it[1];
        bool canCommunicate = false;

        for (auto lang : langKnown[person1])
        {
            if (langKnown[person2].count(lang))
            {
                canCommunicate = true;
                break;
            }
        }
        if (!canCommunicate)
        {
            noCommonLang.push_back({person1, person2});
        }
    }
    // count lang:
    int ans = INT_MAX;

    for (int i = 1; i <= n; ++i)
    {
        unordered_set<int> usersToTeach;

        for (auto &[person1, person2] : noCommonLang)
        {
            // If person1 doesn't know lang: teach it
            if (!langKnown[person1].count(i))
            {
                usersToTeach.insert(person1);
            }
            // If person2 doesn't know lang: teach it
            if (!langKnown[person2].count(i))
            {
                usersToTeach.insert(person2);
            }
        }

        ans = min(ans, (int)usersToTeach.size());
    }

    return ans;
}

int main()
{
    int n = 3;
    vector<vector<int>> languages = {{2}, {1, 3}, {1, 2}, {3}};
    vector<vector<int>> friendships = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
    cout << "\nmin users to teach= " << minimumTeachings(n, languages, friendships);

    return 0;
}