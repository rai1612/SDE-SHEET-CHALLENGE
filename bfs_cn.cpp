#include <bits/stdc++.h>
void solve(int node, vector<vector<int>> &adjl, vector<bool> &vis, vector<int> &bfs)
{
    vis[node] = true;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        bfs.push_back(n);
        sort(adjl[n].begin(), adjl[n].end());
        for (auto i : adjl[n])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<vector<int>> adjl(vertex);
    for (auto i : edges)
    {
        adjl[i.first].push_back(i.second);
        adjl[i.second].push_back(i.first);
    }
    vector<bool> vis(vertex, false);
    vector<int> bfs;
    for (int i = 0; i < vertex; i++)
    {
        if (!vis[i])
        {
            solve(i, adjl, vis, bfs);
        }
    }
    return bfs;
}