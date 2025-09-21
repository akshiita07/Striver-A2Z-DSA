#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem
{
public:
    // movie->(price, shop)
    unordered_map<int, set<pair<int, int>>> moviesAvailable;
    // rented movie tuple:
    set<tuple<int, int, int>> rentedMovies;
    // price lookup for key:
    unoredered_map<long long, int> priceMap;

    // encode movie & shop for key:
    long long key(int shop, int movie)
    {
        return ((long long)shop << 32) | movie;
    }

    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        // n shops
        // entries[i] = [shopi, moviei, pricei]
        for (auto &it : entries)
        {
            int shop = it[0];
            int movie = it[1];
            int price = it[2];
            moviesAvailable[movie].insert({price, shop});
            priceMap[key(shop, movie)] = price;
        }
    }

    vector<int> search(int movie)
    {
        // find cheapest 5 shops having unrented copy of the movie
        // sort shops by price in ascending order
        // if tie-> smaller shopi
        vector<int> res;
        auto &s = moviesAvailable[movie];
        for (auto it = s.begin(); it != s.end() && (int)res.size() < 5; it++)
        {
            res.push_back(it->second);
        }
        return res;
    }

    void rent(int shop, int movie)
    {
        // rent unrented copy of movie from shop
        int price = priceMap[key(shop, movie)];
        moviesAvailable[movie].erase({price, shop});
        rentedMovies.insert({price, shop, movie});
    }

    void drop(int shop, int movie)
    {
        // drops off a previously rented copy of a given movie
        int price = priceMap[key(shop, movie)];
        rentedMovies.erase({price, shop, movie});
        moviesAvailable[movie].insert({price, shop});
    }

    vector<vector<int>> report()
    {
        // returns 5 cheapest rented movies as 2d list res[j] = [shopj, moviej]
        // sort by price in ascending order
        // if tie-> smaller shopj
        // if tie-> smaller moviej
        vector<vector<int>> res;
        for (auto it = rentedMovies.begin(); it != rentedMovies.end() && (int)res.size() < 5; it++)
        {
            auto [price, shop, movie] = *it;
            res.push_back({shop, movie});
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */

int main()
{

    return 0;
}