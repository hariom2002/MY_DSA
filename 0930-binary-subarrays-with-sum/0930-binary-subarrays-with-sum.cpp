class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
         return fnc(nums, goal) - fnc(nums, goal-1);
    }
    
    int fnc(vector<int> &nums, int goal){
        
        if(goal<0)
            return 0;
        int sum=0; // For calculating the current sum
        int i=0;
        int j=0;
        int res=0; 
        
        while(j < nums.size()){
            
            sum+=nums[j];
            
            while(sum> goal){
                sum-=nums[i];
                i++;
            }
            
            
            res+=(j-i+1);
            j++;
        }
        return res;
    }
};