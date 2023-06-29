class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int idx_p = 0, idx_n = 1;
        vector<int> copy(nums);
        
        for(auto n:copy){
            if(n>0){
                nums[idx_p] = n;
                idx_p+=2;
            }
             if(n<0){
                nums[idx_n] = n;
                idx_n+=2;
            }
        }
        return nums;
    }
};