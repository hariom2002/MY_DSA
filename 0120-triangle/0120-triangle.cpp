class Solution {
public:
    int recursion( int i, int j, vector<vector<int>> &triangle,int n, vector<vector<int>> &dp){
        if(i==n-1)
            return triangle[i][j];
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = triangle[i][j] + recursion( i+1, j,triangle,n,dp);
        int left = triangle[i][j] + recursion( i+1,j+1,triangle,n,dp);
        
        return dp[i][j] = min(up, left);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
       vector<vector<int>> dp(n, vector<int> (n, -1)); 
       return recursion(0,0, triangle, n,dp);
    }
};