int lessAndEqual(vector<int> &matrix, int m)
{
    int low = 0, high = matrix.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (matrix[mid] <= m)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return low;
}

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int low = 1, high = 1e5;

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += lessAndEqual(matrix[i], mid);
        }
        if (count <= (n * m) / 2)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return low;
}