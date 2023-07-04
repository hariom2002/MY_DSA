class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(s.begin(), s.end());
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        
        for(int i=0;i<n+1;i++){
            for(int j =0;j<n+1;j++){
                if(i == 0 || j ==0)dp[i][j] =0;
                else if(s[i-1] == t[j-1])dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);   
            } 
        }
        return n - dp[n][n];
    }
};