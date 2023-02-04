int rec(vector<vector<int>> &points, int i, int j,vector<vector<int>>& dp, int n)
{
    if(j == n)
        return 0;
    if(dp[j + 1][i] != -1)
    return dp[j + 1][i];
    for(int k = 0; k < 3; k++)
    {
        if(k == i && j != 0)
            continue;
        else
        {
           dp[j + 1][i] = max(dp[j + 1][i], rec(points,k,j + 1, dp, n) + points[j][k]);
        }
    }  
    return dp[j + 1][i];
    // return max(dp[j + 1][0],max(dp[j + 1][1], dp[j + 1][2]));
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int i = 0, j = 0;
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));

    rec(points,0,0, dp, n);
    return max(dp[1][0],max(dp[1][1], dp[1][2]));
}
