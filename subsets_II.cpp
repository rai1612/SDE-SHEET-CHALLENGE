#include <bits/stdc++.h>
void solve(int idx, vector<int> &arr, int n, vector<int> &ds, vector<vector<int>> &ans)
{

    ans.push_back(ds);

    for (int i = idx; i < n; i++)
    {
        if (i != idx && arr[i] == arr[i - 1])
            continue;

        ds.push_back(arr[i]);
        solve(i + 1, arr, n, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    solve(0, arr, n, ds, ans);
    return ans;
}