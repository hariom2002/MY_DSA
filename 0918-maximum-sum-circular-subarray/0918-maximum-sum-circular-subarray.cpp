class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
// idea - totalSUm - minSumsubarry
        
        int mini = nums[0];
        int currMin = 0;
        int maxi = nums[0];
        int currMax = 0;
        
        int total = 0;
        
        for(auto a: nums){
            currMin = min(currMin+a, a);
            currMax = max(currMax+a, a);
            mini = min(currMin, mini);
            maxi = max(maxi, currMax);
            total +=a;
        }
        return maxi > 0 ? max(maxi, total - mini) : maxi;
        
    }
};