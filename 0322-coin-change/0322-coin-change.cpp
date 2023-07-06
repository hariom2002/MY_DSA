class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int sum = amount;
        vector<vector<long long>> dp(coins.size()+1, vector<long long> (sum+1, 0));
        
         for(int i=0;i<coins.size()+1;i++){
            for(int j =0;j<sum+1;j++){
                if(i == 0)dp[i][j] == INT_MAX-1;
                if(j == 0)dp[i][j] = 0;
            }
         }
         for(int i=1;i<coins.size()+1;i++){
            for(int j =1;j<sum+1;j++){
                if(j%coins[0] == 0)
                    dp[i][j] = j/coins[0];
                else
                    dp[i][j] = INT_MAX;
            }
         }
        
        for(int i=2;i<coins.size()+1;i++){
            for(int j =1;j<sum+1;j++){
                
                if(j>= coins[i-1]){
                    dp[i][j] = min(dp[i][j-coins[i-1]] + 1, dp[i-1][j]);
                }
                    
                else
                dp[i][j] = dp[i-1][j];
                
            }
        }
        if(dp[coins.size()][sum] > amount)return -1;
        return dp[coins.size()][sum];
    }
};