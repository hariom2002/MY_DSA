class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> set;
        
        for(auto x:nums)
            set.insert(x);
        
        int res = 0;
        
        for(auto x:set){
            
          
            int cnt = 0;
            int temp = x;
            
            if(set.find(temp-1)!=set.end())continue;
            
            while(set.find(temp)!=set.end())
                temp--;
            temp++;
            
            while(set.find(temp)!=set.end()){
                // set.erase(temp);
                cnt++;
                temp++;
                
            }
            res = (res<cnt)?cnt:res;
                       
        }
        return res;
    }
};