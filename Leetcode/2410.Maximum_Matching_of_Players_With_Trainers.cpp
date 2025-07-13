#include <bits/stdc++.h>
using namespace std;

int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
{
    // players[i]: ability of the ith player
    // trainers[j]: training capacity of the jth trainer
    // ith player can match with the jth trainer if:  player's ability <= trainer's training capacity
    // 1 player-> 1 or 0 trainers
    // 1 trainer-> 1 or 0 players
    // Return the maximum number of matchings between players and trainers
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());
    // players: {4,6,9} trainers:{2,5,8,8}
    int i = 0;
    int j = 0;
    int matches = 0;
    int n = players.size();
    int m = trainers.size();
    while (i < n && j < m)
    {
        if (players[i] <= trainers[j])
        {
            matches++;
            i++;
            j++;
        }
        else if (players[i] > trainers[j])
        {
            j++;
        }
    }
    return matches;
}

int main()
{
    vector<int> players = {4, 7, 9};
    vector<int> trainers = {8, 2, 5, 8};
    cout << "\nmaximum number of matchings between players and trainers= " << matchPlayersAndTrainers(players, trainers);

    return 0;
}