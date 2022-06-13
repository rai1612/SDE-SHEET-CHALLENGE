#include <bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int n, int k)
{
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq;
    vector<int> ans;
    pq.push({A[0] + B[0], {0, 0}});
    set<pair<int, int>> st;
    st.insert({0, 0});
    while (ans.size() != k)
    {
        int sum = pq.top().first;
        ans.push_back(sum);
        int f = pq.top().second.first;
        int s = pq.top().second.second;
        pq.pop();
        if (st.find({f + 1, s}) == st.end())
        {
            pq.push({A[f + 1] + B[s], {f + 1, s}});
            st.insert({f + 1, s});
        }

        if (st.find({f, s + 1}) == st.end())
        {
            pq.push({A[f] + B[s + 1], {f, s + 1}});
            st.insert({f, s + 1});
        }
    }
    return ans;
}