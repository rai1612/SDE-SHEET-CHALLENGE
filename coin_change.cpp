#include <bits/stdc++.h>

long countWaysToMakeChange(int *denominations, int n, int k)
{
    vector<long> prev(k + 1, 0);
    for (int i = 0; i <= k; i++)
    {
        prev[i] = (i % denominations[0] == 0);
    }

    for (int idx = 1; idx < n; idx++)
    {
        vector<long> curr(k + 1, 0);
        for (int value = 0; value <= k; value++)
        {
            long no = prev[value];
            long yes = 0;
            if (value >= denominations[idx])
            {
                yes = curr[value - denominations[idx]];
            }
            curr[value] = no + yes;
        }
        prev = curr;
    }
    return prev[k];
}