#include <bits/stdc++.h>
double median(vector<int> a, vector<int> b)
{
    if (b.size() < a.size())
        return median(b, a);

    int n1 = a.size(), n2 = b.size();

    int low = 0, high = n1;
    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int l1, l2, r1, r2;
        if (cut1 == 0)
        {
            l1 = INT_MIN;
            r1 = a[0];
        }
        else if (cut1 == n1)
        {
            l1 = a[n1 - 1];
            r1 = INT_MAX;
        }
        else
        {
            l1 = a[cut1 - 1];
            r1 = a[cut1];
        }

        if (cut2 == 0)
        {
            l2 = INT_MIN;
            r2 = b[0];
        }
        else if (cut2 == n2)
        {
            r2 = INT_MAX;
            l2 = b[n2 - 1];
        }
        else
        {
            r2 = b[cut2];
            l2 = b[cut2 - 1];
        }

        if (l1 <= r2 && l2 <= r1)
        {
            if ((n1 + n2) % 2 == 0)
                return ((max(l1, l2) + min(r1, r2)) / 2.0);
            else
                return max(l1, l2);
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.00;
}
