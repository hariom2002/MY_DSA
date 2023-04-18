class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        
        // using two pointer and 2-sum approach
        vector<vector<int>> res;
        if(nums.size()== 0){
            return res;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                long target2 = target - nums[i] - nums[j] ;

                int front = j+1;
                int back = n-1;

                while(back>front){
                    long sum = nums[front] + nums[back];
                    if(target2 >sum )front++;
                    else if(target2 < sum)back--;
                    else{
                        vector<int> quad(4, 0);
                        quad[0] = (nums[i]);
                        quad[1] = (nums[j]);
                        quad[2] = (nums[front]);
                        quad[3] = (nums[back]);

                        res.push_back(quad);

                        while(front<back && nums[front] == quad[2])front++;
                        while(front<back && nums[back] == quad[3])back--;
                    }
                    
                }
                while(j+1<n && nums[j+1] == nums[j])j++;
            }
            while(i+1 < n && nums[i+1] == nums[i])i++;
        }
        return res;
    }
};