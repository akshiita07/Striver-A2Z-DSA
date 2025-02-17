#include <bits/stdc++.h>
using namespace std;

// backtrack: also pass by reference so value gets updated
void backtrack(unordered_map<char, int> &hashMap, int &count)
{
    for (auto &it : hashMap)
    {
        char letter = it.first;
        int freq = it.second;
        if (freq > 0)
        {
            // use it in sequence
            // so decrease its frequency
            it.second--;
            // increase count of ans:
            count++;
            // backtrack: try to extend this current sequence
            backtrack(hashMap, count);
            // if it returns false then undo changes so reverse everything u did above:
            it.second++;
        }
    }
}

int numTilePossibilities(string tiles)
{
    int n = tiles.length();           // no of tiles
    unordered_map<char, int> hashMap; // map char->frequency
    for (int i = 0; i < n; i++)
    {
        // letter printed on tile:
        char letter = tiles[i];
        hashMap[letter]++;
    }
    // return no of possible non-empty sequences of letters
    int count = 0;
    backtrack(hashMap, count);
    return count;
}

int main()
{
    string tiles = "AAB";
    cout << "\nNo of possible non-empty sequences of letters= " << numTilePossibilities(tiles);

    return 0;
}