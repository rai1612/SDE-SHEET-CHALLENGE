bool isCyclic(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis)
{
    vis[node] = true;
    dfsVis[node] = true;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            vis[i] = true;
            if (isCyclic(i, adj, vis, dfsVis))
                return true;
        }
        else
        {
            if (dfsVis[i] == true)
                return true; // if both vis and dfsVis are true, cycle present because the same node is visited again in its dfs call itself
        }
    }
    dfsVis[node] = false; // marking unvisited while going back in recursion
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<bool> vis(n + 1, false), dfsVis(n + 1, false);
    vector<int> adj[n + 1];
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (isCyclic(i, adj, vis, dfsVis))
                return true;
        }
    }
    return false;
}