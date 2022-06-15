void solve(int idx, vector<int> &num, vector<int> &ans, int sum)
{
    if (idx == num.size())
    {
        ans.push_back(sum);
        return;
    }

    solve(idx + 1, num, ans, sum + num[idx]);

    solve(idx + 1, num, ans, sum);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    solve(0, num, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}