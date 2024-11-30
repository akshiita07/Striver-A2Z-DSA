// NOT UNDERSTOOD!!
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
{
    // pairs[i] = [starti, endi]
    // valid if: endi-1 == starti
    // Return any valid arrangement of pairs
    int m = pairs.size();
    int n = pairs[0].size();

    unordered_map<int, vector<int>> graph;       // Maps a node to its neighbors
    unordered_map<int, int> inDegree, outDegree; // To track in-degree and out-degree of nodes

    // update in/out-degrees
    for (int i = 0; i < m; i++)
    {
        int start = pairs[i][0];
        int end = pairs[i][1];
        graph[start].push_back(end); // Add a directed edge from 'start' to 'end'
        outDegree[start]++;          // Increment out-degree of 'start'
        inDegree[end]++;             // Increment in-degree of 'end'
    }

    // For an Eulerian path, the starting node has more outgoing edges than incoming.
    // Starting node for the Eulerian path
    int startNode = pairs[0][0];
    for (auto it = graph.begin(); it != graph.end(); it++)
    {
        int node = it->first;
        if (outDegree[node] > inDegree[node])
        {
            startNode = node;
            break;
        }
    }

    // Use Hierholzer's Algorithm to find the Eulerian path
    vector<int> path;   // store the Eulerian path in reverse order
    stack<int> st;      // for DFS traversal
    st.push(startNode); // Start DFS from the identified starting node from eulerian

    while (!st.empty())
    {
        int node = st.top(); // Get the node at the top of the stack
        if (!graph[node].empty())
        {
            // If the current node has neighbors (outgoing edges)
            int nextNode = graph[node].back(); // Get the next node from the adjacency list
            graph[node].pop_back();            // Remove the edge to prevent revisiting
            st.push(nextNode);                 // Push the next node onto the stack
        }
        else
        {
            // If no more neighbors, this node is finished
            path.push_back(node); // Add it to the path
            st.pop();             // Remove it from the stack
        }
    }

    // Reverse the path to get the correct order
    reverse(path.begin(), path.end());

    //  Convert the Eulerian path into a valid arrangement of pairs
    vector<vector<int>> result; // This will store the valid arrangement
    for (int i = 0; i < path.size() - 1; i++)
    {
        result.push_back({path[i], path[i + 1]}); // Convert consecutive nodes into pairs
    }

    return result; // Return the valid arrangement
}

int main()
{
    vector<vector<int>> pairs = {{5, 1}, {4, 5}, {11, 9}, {9, 4}};
    vector<vector<int>> ans = validArrangement(pairs);
    cout << "Valid arrangement is: \n";
    for (auto it : ans)
    {
        for (auto elem : it)
        {
            cout << elem << " ";
        }
        cout << "  ,  ";
    }

    return 0;
}