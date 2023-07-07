class Solution {
public:
    
    int findSum(vector<int> nums, int k){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            nums[i] = ceil((double)(nums[i])/(double)(k));
            sum+=nums[i];
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        int res = INT_MAX;
        
        while(high>=low){
            int mid = low+(high-low)/2;
            
            if(findSum(nums, mid) <= threshold){
                res=min(res, mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};