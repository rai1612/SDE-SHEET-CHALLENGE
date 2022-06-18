#include <bits/stdc++.h>
bool bipartite(int node, vector<int> adj[], vector<int> &color)
{
    color[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        for (auto i : adj[n])
        {
            if (color[i] == -1)
            {
                color[i] = 1 - color[n];
                q.push(i);
            }
            else
            {
                if (color[i] == color[n])
                    return false;
            }
        }
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges)
{
    // edges is an adjacency matrix
    int n = edges.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartite(i, adj, color))
                return false;
        }
    }
    return true;
}