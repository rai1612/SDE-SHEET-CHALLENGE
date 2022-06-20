void solve(int idx, vector<int> &arr, int n, int k, vector<int> &ds, vector<vector<int>> &ans)
{
    if (idx == n)
    {
        if (k == 0)
            ans.push_back(ds);
        return;
    }
    ds.push_back(arr[idx]);
    solve(idx + 1, arr, n, k - arr[idx], ds, ans);
    ds.pop_back();
    solve(idx + 1, arr, n, k, ds, ans);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, arr, n, k, ds, ans);
    return ans;
}