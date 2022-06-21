#include <bits/stdc++.h>
void solve(int idx, vector<int> &arr, int n, int target, vector<int> &ds, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (i > idx && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;

        ds.push_back(arr[i]);
        solve(i + 1, arr, n, target - arr[i], ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    solve(0, arr, n, target, ds, ans);
    return ans;
}
