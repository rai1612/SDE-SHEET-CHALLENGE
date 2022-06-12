#include <bits/stdc++.h>
bool isCyclePresent(int src, vector<int> adj[], vector<bool> &vis)
{
    // queue will store {node, parent}.
    queue<pair<int, int>> q;
    q.push({src, -1}); // initially the parent is taken as -1.
    vis[src] = true;

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                q.push({i, node});
                vis[i] = true;
            }
            else
            {
                if (parent != i)
                {                // if visited, then it can be its parent too because bfs starts from its parent only. If it is parent then no cycle is detected, but if not, then there is cycle.
                    return true; // If found any cycle no need to check any futher.
                }
            }
        }
    }
    return false; // no cycle found for the given src.
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (isCyclePresent(i, adj, vis))
            { // if any node found cycle, no need to check futher.
                return "Yes";
            }
        }
    }
    return "No";
}
