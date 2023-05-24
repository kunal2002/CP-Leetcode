vector<int> spiralMatrix(vector<vector<int>>&MATRIX) {
    // Write your code here.
    int n = MATRIX.size(), m = MATRIX[0].size();
    int top = 0, right = m - 1, left = 0, bottom = n - 1;
    vector<int> vec;
    while(left <= right && top <= bottom)
    {
        for(int i = left; i <= right; i++)
        vec.push_back(MATRIX[top][i]);
        top++;
        for(int i = top; i <= bottom; i++)
            vec.push_back(MATRIX[i][right]);
        right--;
        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
            vec.push_back(MATRIX[bottom][i]);
            bottom--;
        }
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
            vec.push_back(MATRIX[i][left]);
            left++;
        }
    }
    return vec;
}
