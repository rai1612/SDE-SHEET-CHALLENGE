#include <bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size() > k)
            maxHeap.pop();
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
            minHeap.pop();
    }
    return {maxHeap.top(), minHeap.top()};
}