class Solution {
public:
//     int solve(int n, int prev, vector<int>& nums, vector<vector<int>>& memo) {
//         if (n < 0) return 0;
//         if (memo[n][prev + 1] != -1) return memo[n][prev + 1];

//         int notTake = solve(n - 1, prev, nums, memo);
//         int take = 0;
//         if (prev == -1 || nums[n] > nums[prev]) {
//             take = 1 + solve(n - 1, n, nums, memo);
//         }

//         memo[n][prev + 1] = max(take, notTake);
//         return memo[n][prev + 1];
//     }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        // return solve(n - 1, -1, nums, memo);
        
         vector<vector<int>> dp(n+1, vector<int> (n+1,0));
       
       for(int ind = n-1;ind>=0; ind--){
           for(int prev = ind-1;prev >=-1; prev--){
               
               int take =0 ; 
               if(prev == -1 || nums[ind]>nums[prev])
                 take = 1 + dp[ind+1][ind+1];
                
                int notTake = 0 + dp[ind+1][prev+1];
                dp[ind][prev+1] = max(take, notTake);
           }    
       }
       return dp[0][0];
    }
};
