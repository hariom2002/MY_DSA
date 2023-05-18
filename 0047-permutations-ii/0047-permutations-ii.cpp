class Solution {
public:
    
    vector<vector<int>> res;
    vector<int> curr;
    
    void fnc(vector<int> &nums,vector<bool> &vis)
    {
        if(curr.size() == nums.size())
        {
            res.push_back(curr);
            return;
        }
         
        for(int i=0;i<nums.size();i++){

            if(!vis[i]){
             vis[i]=true;
             curr.push_back(nums[i]);
             fnc(nums,vis);

             vis[i]=false;
             curr.pop_back();
            }
        }       
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> vis(nums.size(), false);
        fnc(nums,vis);
        
        sort( res.begin(), res.end() );
        res.erase( unique( res.begin(), res.end() ), res.end() );
        return res;
    }
};