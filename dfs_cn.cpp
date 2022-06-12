void DFS(int node, vector<int> adj[], vector<bool> &vis, vector<int> &ans)
{
    vis[node] = true;
    ans.push_back(node);
    for (auto i : adj[node])
    {
        if (!vis[i])
            DFS(i, adj, vis, ans);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>> dfs;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            vector<int> ans;
            DFS(i, adj, vis, ans);
            dfs.push_back(ans);
        }
    }
    return dfs;
}