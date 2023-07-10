class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> res;
        
        map<int,int> map;
        set<int> set;
        for(auto s: nums1)
            set.insert(s);
        
        for(int i=nums2.size()-1;i>=0;i--){
            if(!st.size()){
                st.push(nums2[i]);
            map[nums2[i]] = -1;
        }
                
            else{
                while(st.size() && st.top() <= nums2[i])
                    st.pop();
                 map[nums2[i]] = st.size()==0?-1:st.top();
                st.push(nums2[i]);
            }
            
        }
        for(auto x: nums1){
            if(map.find(x)!=map.end()){
                res.push_back(map[x]);
            }
        }
        return res;
    }
};