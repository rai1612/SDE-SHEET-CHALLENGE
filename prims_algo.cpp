#include <bits/stdc++.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int, int>> adj[n + 1];
    for (auto i : g)
    {
        int u = i.first.first;
        int v = i.first.second;
        int w = i.second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int key[n + 1], parent[n + 1], mst[n + 1];
    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = 0;
    }

    key[1] = 0;
    parent[1] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // wt->node
    pq.push({0, 1});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        mst[u] = 1; // taken into mst

        for (auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;

            if (!mst[v] && wt < key[v])
            {
                parent[v] = u;
                key[v] = wt;
                pq.push({key[v], v});
            }
        }
    }

    vector<pair<pair<int, int>, int>> vpp;

    for (int i = 2; i <= n; i++)
    {
        int u = parent[i];
        int wt = key[i];
        vpp.push_back({{u, i}, wt});
    }
    return vpp;
}
