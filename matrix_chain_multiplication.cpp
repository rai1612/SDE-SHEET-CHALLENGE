
int solve(int i, int j, vector<int> &arr, int N, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int minCost = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost = (arr[i - 1] * arr[k] * arr[j]) + solve(i, k, arr, N, dp) + solve(k + 1, j, arr, N, dp);
        minCost = min(minCost, cost);
    }
    return dp[i][j] = minCost;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solve(1, N - 1, arr, N, dp);
}