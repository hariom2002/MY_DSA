class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size()-1;
        int res = INT_MAX-1;
        while(high>=low){
            int mid = low+ (high - low)/2;
            
//             when array is left sorted
            if(nums[mid] >= nums[low]){
                 res =min(res, nums[low]);
                 low = mid+1;
            }
            else{
                 res =min(res, nums[mid]);
                 high = mid-1;                 
            }
        }
        return res;
    }
};