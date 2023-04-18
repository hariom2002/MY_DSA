class Solution {
public:
    
    int solve(int indx, bool buy, vector<int> &prices, vector<vector<int>> &dp){
        
        if(indx == prices.size())
            return 0;
        int profit = 0;
        
        if(dp[indx][buy]!=-1)
            return dp[indx][buy];
        if(buy){
            profit = max(-prices[indx] + solve(indx+1, 0, prices, dp), 0 + solve(indx+1, 1, prices, dp));
        }
        else{
            profit = max(prices[indx]+ solve(indx+1, 1, prices, dp), 0+ solve(indx+1, 0, prices, dp));
        }
        return dp[indx][buy] =profit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return solve(0, 1, prices, dp);
    }
};