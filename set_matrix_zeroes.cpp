#include <bits/stdc++.h>
void setZeros(vector<vector<int>> &matrix)
{
    int col0 = 1; // col = 1 means the first column does not contain any 0
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
            col0 = 0; // if any of the first column element is 0 then the whole column is to be set 0. col0 = 0 means that only.
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    // Now traversing from the back
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 1; j--)
        {
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
            {
                matrix[i][j] = 0;
            }
        }
        // setting the first column elements to 0
        if (col0 == 0)
            matrix[i][0] = 0;
    }
}