#include <bits/stdc++.h>
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int idx1 = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (permutation[i] < permutation[i + 1])
        {
            idx1 = i;
            break;
        }
    }
    // If the given array is in its max permuation
    if (idx1 == -1)
    {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }
    int idx2 = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (permutation[i] > permutation[idx1])
        {
            idx2 = i;
            break;
        }
    }
    swap(permutation[idx1], permutation[idx2]);
    reverse(permutation.begin() + idx1 + 1, permutation.end());
    return permutation;
}