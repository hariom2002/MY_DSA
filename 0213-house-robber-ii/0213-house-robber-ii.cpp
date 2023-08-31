class Solution {
public:
    
    int robber(vector<int> &nums, int a, int b){
        
        int n = nums.size();
        vector<int> dp(n+1, -1);
        
        dp[a] = nums[a];
        dp[a + 1] = max(nums[a], nums[a + 1]);
        
        for(int i = a + 2; i <= b; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        
        return dp[b];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
};
