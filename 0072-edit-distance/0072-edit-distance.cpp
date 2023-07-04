class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        
        return recursion(word1, word2, n-1, m-1, dp);
    }
    
    int recursion(string &str1, string &str2, int i, int j,vector<vector<int>> &dp){
        
        if(j <0)return i+1;
        if(i < 0)return j+1;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        if(str1[i] == str2[j]){
            return dp[i][j] = ( 0 + recursion(str1, str2, i-1, j-1, dp));
        }
        else{
            int insert = recursion(str1, str2, i, j-1, dp) ;
            int remove = recursion(str1, str2, i-1, j, dp) ;
            int replace = recursion(str1, str2, i-1, j-1, dp) ;
            
            return  dp[i][j] = 1+  min(insert, min(remove, replace));
        }
    }
};