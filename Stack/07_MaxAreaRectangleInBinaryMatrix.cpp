/* https://leetcode.com/problems/maximal-rectangle/

*/

void NextSmallerToLeft(vector<int> &arr, vector<int> &left)
{
    int n = arr.size();
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
}

void NextSmallerToRight(vector<int> &arr, vector<int> &right)
{
    int n = arr.size();
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }
}

int MaximumAreaHistogram(vector<int> &arr)
{
    int n = arr.size();
    vector<int> left(n), right(n);
    NextSmallerToLeft(arr, left);
    NextSmallerToRight(arr, right);

    int maxArea = -1;
    for (int i = 0; i < n; i++)
    {
        int ithArea = arr[i] * (right[i] - left[i] - 1);
        if (maxArea < ithArea)
            maxArea = ithArea;
    }

    return maxArea;
}

int MaxAreaRectangleInBinaryMatrix(vector<vector<char>> &matrix)
{
    vector<int> v;
    int n = matrix.size(), m = matrix[0].size();
    for (int j = 0; j < m; j++)
        v.push_back(matrix[0][j]);

    int MaximumArea = MaximumAreaHistogram(v);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
                v[j] = 0;
            else
                v[j] += matrix[i][j];
        }
        MaximumArea = max(MaximumArea, MaximumAreaHistogram(v) );
    }
    return MaximumArea;
}