#include <bits/stdc++.h>
using namespace std;

// Topological Sorting (Kahn's Algorithm)
vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
{
    int n = recipes.size();
    // ith recipe: name recipes[i]->can create it if have all
    // Return a list of all the recipes that you can create ingredients[i]

    // ingredients needed for receipe:
    unordered_map<string, int> inDegree;

    // which ingredients lead to which receipe:
    unordered_map<string, vector<string>> graph;

    // supplies available:
    unordered_set<string> available(supplies.begin(), supplies.end());

    // build graph:
    for (int i = 0; i < n; i++)
    {
        for (auto &it : ingredients[i])
        {
            graph[it].push_back(recipes[i]);
            inDegree[recipes[i]]++;
        }
    }

    // BFS:
    queue<string> qu;
    vector<string> ans;

    for (auto &it : supplies)
    {
        qu.push(it);
    }

    while (!qu.empty())
    {
        string current = qu.front();
        qu.pop();
        // if it is reciepe then make it:
        if (find(recipes.begin(), recipes.end(), current) != recipes.end())
        {
            ans.push_back(current);
        }
        for (auto &it : graph[current])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
            {
                qu.push(it);
            }
        }
    }

    return ans;
}

int main()
{
    vector<string> &recipes = {};
    vector<vector<string>> &ingredients = {};
    vector<string> &supplies = {};
    vector<string> ans = findAllRecipes(recipes, ingredients, supplies);
    for (auto it : ans)
    {
        cout << it << endl;
    }

    return 0;
}