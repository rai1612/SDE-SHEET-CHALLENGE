#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
    int i = 0, j = 0;
    unordered_map<char, int> mp;
    int ans = 0;
    while (j < input.length())
    {
        mp[input[j]]++;
        if (mp.size() < j - i + 1)
        {
            ans = max(ans, j - i);
            while (mp.size() < j - i + 1)
            {
                mp[input[i]]--;
                if (mp[input[i]] == 0)
                    mp.erase(input[i]);
                i++;
            }
        }
        j++;
    }
    ans = max(ans, j - i);
    return ans;
}