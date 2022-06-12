#include <bits/stdc++.h>
void dfs(int src, vector<int> adj[], vector<bool> &vis, stack<int> &st)
{
    vis[src] = true;
    for (auto i : adj[src])
    {
        if (!vis[i])
            dfs(i, adj, vis, st);
    }
    st.push(src);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<bool> vis(v, false);
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }
    vector<int> toposort;
    while (!st.empty())
    {
        toposort.push_back(st.top());
        st.pop();
    }
    return toposort;
}