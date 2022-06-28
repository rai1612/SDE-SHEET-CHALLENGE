
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<int> prev(k + 1, 0);

    // if target is equal to 0 then it is always true

    prev[0] = 1;

    if (arr[0] <= k)
        prev[arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(k + 1, 0);
        curr[0] = 1;
        for (int j = 1; j <= k; j++)
        {
            int taken = prev[j];
            int notTaken = 0;
            if (arr[i] <= j)
            {
                notTaken = prev[j - arr[i]];
            }
            curr[j] = (taken || notTaken);
        }
        prev = curr;
    }
    return prev[k];
}