#include <bits/stdc++.h>
using namespace std;

// bfs to find shortest dist between start & end
int useBFStoFindShortestDist(vector<vector<int>> &adjacencyList,int n){
    // distance array with all dist as infinity initially:
    vector<int> distances(n,INT_MAX);
    // for bfs take queue
    queue<int> qu;
    // dist of city 0 from 0 is 0
    distances[0]=0;
    // push starting node in queue
    qu.push(0);
    // BFS:
    while(!qu.empty()){
        int current=qu.front();
        qu.pop();
        for(int i=0;i<adjacencyList[current].size();i++){
            int neighbor=adjacencyList[current][i];
            if(distances[neighbor]==INT_MAX){       //city not visited
                distances[neighbor]=distances[current]+1;
                qu.push(neighbor);
            }
        }
    }
    return distances[n-1];
}

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
{
    // n cities numbered from 0 to n - 1
    // Initially, unidirectional road from city i to city i + 1
    // queries[i] = [ui, vi] :addition of a new unidirectional road from city ui to city vi
    // find the length of the shortest path from city 0 to city n - 1
    // return answer[i] :length of shortest path from city 0 to city n - 1 after processing the first i + 1 queries
    vector<int> answer;

    // execute first query:
    // find shortest dist between 1st & last node
    // add it to answer vector
    // then execute second query
    // now again try to find shortest dist between 1st & last node & add it to answer vector

    // adjacency list to represent graph:
    vector<vector<int>> adjacencyList(n);
    // add road frm city i to i+1 in it
    for(int i=0;i<n-1;i++){
        adjacencyList[i].push_back(i+1);
    }

    // for each query:
    for(auto &query:queries){
        // query[i][j] ie add path from i to j
        int start=query[0]; 
        int end=query[1]; 
        // add this new road combination:
        adjacencyList[start].push_back(end);

        // find shortest path between city 0 & city n-1
        int shortestPath=useBFStoFindShortestDist(adjacencyList,n);
        answer.push_back(shortestPath);
    }
    return answer;
}

int main()
{
    int n = 5;
    vector<vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};
    // Output: [3,2,1]
    vector<int> ans = shortestDistanceAfterQueries(n, queries);
    cout << "Shortest dist are: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}