class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i=0;i<nums.size()-2;i++){

            if (i == 0 || (i > 0 && nums[i] != nums[i-1])){
                 int sum = 0 - nums[i];

            int low = i+1;
            int high = nums.size()-1;

           while(high>low){
                if((nums[low] + nums[high]) == sum){
                vector<int> temp(3, 0);
                temp[0] = nums[i];
                temp[1] = nums[low];
                temp[2] = nums[high];

                res.push_back(temp);

                // while(nums[low] == temp[1])low++;
                // while(nums[high] == temp[2])high--;
                while (low < high && nums[low] == nums[low+1]) low++;
                while (low < high && nums[high] == nums[high-1]) high--;
                
                low++; high--;
            }
           else if(nums[low]+nums[high] > sum)high--;
           else low++; 
                // else if (nums[low] + nums[high] < sum) low++;
                // else high--;

           }

            }
           
        }
        return res;
    }
};