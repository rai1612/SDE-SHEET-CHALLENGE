#include <bits/stdc++.h>
vector<vector<long long>> printPascal(int n)
{
    vector<vector<long long>> pascal;
    for (int i = 1; i <= n; i++)
    {
        vector<long long> v(i);
        v[0] = 1;
        v[i - 1] = 1;
        for (int j = 1; j <= i - 2; j++)
        {
            v[j] = pascal[i - 2][j - 1] + pascal[i - 2][j];
        }
        pascal.push_back(v);
    }
    return pascal;
}
