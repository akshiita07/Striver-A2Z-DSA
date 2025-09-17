#include <bits/stdc++.h>
using namespace std;

// hash map1: food item-> (cuisine,rating)
// hash map2: cuisine -> food (sorted by ratings & lexicographically smaller name)
class FoodRatings
{
    unordered_map<string, pair<string, int>> foodMap;
    unordered_map<string, set<pair<int, string>>> cuisineMap;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines,
                vector<int> &ratings)
    {
        // Initializes the system of food,cuisine & ratings of length n
        int n = foods.size();
        for (int i = 0; i < n; i++)
        {
            // populate the maps:
            foodMap[foods[i]] = {cuisines[i], ratings[i]};
            cuisineMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        // Changes the rating of the food item with the name food
        string oldCuisine = foodMap[food].first;
        int oldRating = foodMap[food].second;
        // change rating in food map
        foodMap[food].second = newRating;
        // change rating in cuisine map
        cuisineMap[oldCuisine].erase({-oldRating, food});
        cuisineMap[oldCuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine)
    {
        // Returns the name of the food item that has the highest rating for the
        // given type of cuisine if tie-> lexicographically smaller name (jo
        // dictionary mai pehle aaye)
        return cuisineMap[cuisine].begin()->second;
    }
};

int main()
{

    return 0;
}