string kthPermutation(int n, int k)
{
    int fact = 1;
    vector<int> v(n);
    v[n - 1] = n;
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        v[i - 1] = i;
    }

    string ans;
    k--; // as 0 based indexing so we need (k-1)th sequence
    while (true)
    {
        ans.push_back(char(v[k / fact] + '0'));
        v.erase(v.begin() + (k / fact));
        if (v.size() == 0)
            break;

        k %= fact;
        fact /= v.size();
    }
    return ans;
}
