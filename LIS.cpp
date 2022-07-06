#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &heights, int n)
{
    vector<int> dp(n, 1), hash(n, 0);
    for (int i = 0; i < n; i++)
        hash[i] = i;
    int ans = 1;
    int k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (heights[j] < heights[i])
            {
                if (dp[i] < dp[j] + 1)
                {
                    hash[i] = j;
                    dp[i] = 1 + dp[j];
                }
            }
        }
        if (dp[i] > ans)
        {
            k = i;
            ans = dp[i];
        }
    }
    // printing lis
    vector<int> lis;
    while (true)
    {
        lis.push_back(heights[k]);
        k = hash[k];
        if (k == hash[k])
            break;
    }
    lis.push_back(heights[k]);
    reverse(lis.begin(), lis.end());
    for (auto it : lis)
        cout << it << " ";
    cout << endl;
    // the length of lis
    return ans;
}

int main()
{
    vector<int> v = {5, 2, 6, 1, 3, 4};
    cout << LIS(v, 6);
    return 0;
}