#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    int buy = INT_MAX, ans = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < buy)
            buy = prices[i];
        else
        {
            ans = max(ans, prices[i] - buy);
        }
    }
    return ans;
}