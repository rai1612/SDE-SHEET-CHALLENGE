#include <bits/stdc++.h>
vector<int> bfs(vector<int> adj[], int v)
{
    vector<int> ans;
    vector<int> indegree(v, 0);
    // calculating the indegrees of all the nodes
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    // pushing all the nodes with 0 indegrees to the queue so that they stay in the beginning of the topological sort
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    // bfs
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto i : adj[node])
        {
            indegree[i]--; // because node is taken into ans, indegree of all its adjacent nodes decrease by 1
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    return ans;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> toposort = bfs(adj, v);

    return toposort;
}