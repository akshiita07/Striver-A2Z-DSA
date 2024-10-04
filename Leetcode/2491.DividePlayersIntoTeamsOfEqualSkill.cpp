#include <bits/stdc++.h>
using namespace std;

long long dividePlayers(vector<int> &skill)
{
    // Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal
    // chemistry of a team is equal to the product of the skills of the players on that team
    // Return sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.
    int n = skill.size();
    if (n % 2 != 0)
    {
        // if odd length then not possible to divide
        return -1;
    }
    long long chemistry = 0;
    // sort skills
    sort(skill.begin(), skill.end());
    // check if target sum possible:
    int target = skill[0] + skill[n - 1];
    // check if all possible r combinations
    for (int i = 0; i < n / 2; i++)
    {
        if (skill[i] + skill[n - i - 1] != target)
        {
            return -1;
        }
        chemistry = chemistry + (skill[i] * skill[n - i - 1]);
    }
    return chemistry;
}

int main()
{
    vector<int> skill = {3, 2, 5, 1, 3, 4};
    cout << "\nThe chemistry of skills when divided into n/2 pairs is: " << dividePlayers(skill);

    return 0;
}