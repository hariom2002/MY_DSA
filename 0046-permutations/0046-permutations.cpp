class Solution {
public:
    void solve( vector<int> &nums, vector<int> &temp, vector<int> &vis, vector<vector<int>> &res){

        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]= 1;
                temp.push_back(nums[i]);
                solve(nums, temp, vis,res);
                temp.pop_back();
                vis[i]= 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> vis(nums.size(), 0);
        vector<vector<int>> res;
        vector<int> temp;

        solve(nums, temp, vis, res);
        return res;
    }
};