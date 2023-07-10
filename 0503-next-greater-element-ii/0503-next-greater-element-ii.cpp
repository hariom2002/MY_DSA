class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res;
        
        for(int i=2*n-1;i>=0;i--){
            if(st.empty()){
                st.push(nums[i%n]);
                if(i<n)
                res.push_back(-1);
            }
            else{
                while(st.size() && st.top() <= nums[i%n])
                    st.pop();
                if(i<n)
                    res.push_back(st.size()==0?-1:st.top());
                st.push(nums[i%n]);
            }   
        }
        reverse(res.begin(), res.end());
        return res;
    }
};