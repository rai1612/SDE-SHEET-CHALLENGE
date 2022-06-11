#include <bits/stdc++.h>
int LongestSubsetWithZeroSum(vector<int> A)
{
    int n = A.size();
    unordered_map<int, int> mp;
    // value->index
    mp[0] = -1;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (mp.find(sum) != mp.end())
            ans = max(ans, i - mp[sum]);
        else
            mp[sum] = i;
    }
    return ans;
}