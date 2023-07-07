class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        
//         we are applying binary serach on array excluding first and last element
//         so check those elements seperately
        
        if(n == 1 )return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];
        
        int low = 1;
        int high = n-2;
        
        
        while(high>=low){
            int mid = low+(high-low)/2;
            
            if(nums[mid] != nums[mid-1] && nums[mid]!= nums[mid+1])
                return nums[mid];
            
            if((mid%2 == 0 && nums[mid+1] == nums[mid]) || (mid%2 == 1 && nums[mid-1] == nums[mid]) ){
                low=mid+1;
                
            }
            else{
                high=mid-1;
            }
        }
          return -1;
        
    }
};