class Solution {
public:
    vector<int> curr;
    vector<vector<int>> res;
    
    void fnc(vector<int> &candidates, int &target, int sum, int i)
    {
        if(sum==target)
        {
            res.push_back(curr);
            return;
        }
       while(i < candidates.size() && sum <= target)
        {
            curr.push_back(candidates[i]);
            fnc(candidates, target,sum + candidates[i], i);
            i++;
            curr.pop_back();
                  
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        fnc(candidates, target,0,0);
        
        return res;
    }
};