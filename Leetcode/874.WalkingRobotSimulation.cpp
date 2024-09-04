#include <bits/stdc++.h>
using namespace std;

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
{
    // robot starts at point (0,0)
    int maxDist=0;

    // three possible types of commands:
    // -2: Turn left 90 degrees.
    // -1: Turn right 90 degrees.
    // 1 <= k <= 9: Move forward k units, one unit at a time.

    // North means +Y direction.        dir=0
    // East means +X direction.     dir=1
    // South means -Y direction.        dir=2
    // West means -X direction.     dir=3
    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // The ith obstacle is at grid point obstacles[i] = (xi, yi)
    int x=0;
    int y=0;
    // current direction is north
    int dir = 0;

    // If robot runs into an obstacle->stay in its current location and move on to the next command
    // convert obstacles to set of pairs for easy lookup
    set<pair<int,int>> setOfObstacles;
    for(auto it:obstacles){
        setOfObstacles.insert({it[0],it[1]});
    }

    // Return the maximum Euclidean distance that the robot ever gets from the origin squared  ie for (x,y)=x^2+y^2

    int n = commands.size();
    for (int i = 0; i < n; i++)
    {
        if (commands[i] == -2)
        {
            // left 90
            // From North (0) to West (3)
            // From West (3) to South (2)
            // From South (2) to East (1)
            // From East (1) to North (0)
            dir = (dir + 3) % 4;
        }
        else if (commands[i] == -1)
        {
            // right 90
            // From North (0) to East (1)
            // From East (1) to South (2)
            // From South (2) to West (3)
            // From West (3) to North (0)
            dir = (dir + 1) % 4;
        }
        else if (commands[i] >= 1 || commands[i] <= 9)
        {
            // move 1 step at a time in same direction & check for obstacles
            for(int j=0;j<commands[i];j++){
                // find new x & y coordinate
                int newX=x+direction[dir].first;
                int newY=y+direction[dir].second;
                // check if it is not equal to obstacle
                if(setOfObstacles.find({newX,newY})==setOfObstacles.end()){
                    // ie NOT found:
                    x=newX;
                    y=newY;
                    maxDist=max(maxDist,x*x+y*y);
                }else{
                    // ie found:
                    break;
                }
            }
        }
    }

    return maxDist;
}

int main()
{
    vector<int> commands = {4, -1, 4, -2, 4};
    vector<vector<int>> obstacles = {{2, 4}};
    cout << "\nThe maximum distance= " << robotSim(commands, obstacles);
    // Output: 65
    return 0;
}