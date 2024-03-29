class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int exp_sum = n*(n+1)/2;
        
        int sum = 0;
        for(auto x: nums)
            sum+=x;
        
        return exp_sum - sum;
    }
};