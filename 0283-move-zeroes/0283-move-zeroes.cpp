class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return;
        
        int zr = 0;
        
        int j = 0;
       for(int i=1;i<n;i++){
           if(nums[j] != 0){j++;continue;}
            if(nums[j] == 0 && nums[i] != 0){
                nums[j] = nums[i];
                nums[i] = 0;
                j++;
            }
           
       }
        
    }
};