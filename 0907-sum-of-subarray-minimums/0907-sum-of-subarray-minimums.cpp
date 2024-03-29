class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
//         using monotonic stack (standard type)
        
        
        int MOD = 1e9+7;
        int n = arr.size();
        vector<int> left(n,-1),right(n,n);
        
//         finding left minimum
        stack<int> st;
        
        for(int i=0; i<n; i++)
        {
            while(st.size() && arr[i] < arr[st.top()]) st.pop();
            if(st.size()) left[i] = i - st.top();
            else left[i] = i+1;
            st.push(i);
        }
        
         while(st.size()) st.pop();
        
        // Right
        for(int i=n-1; i>=0; i--)
        {
            while(st.size() && arr[i] <= arr[st.top()]) st.pop();
            if(st.size()) right[i] = st.top() - i;
            else right[i] = n - i;
            st.push(i);
        }
        // for(int i=0;i<left.size();i++){
        //     cout<<left[i]<<" ";
        // }cout<<endl;
        // for(int i=0;i<right.size();i++){
        //     cout<<right[i]<<" ";
        // }
        
        int res = 0;
        for(int i=0; i<n; i++)
        {
            long long prod = (left[i]*right[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        }
        
        return res%MOD;
        return 0;
    }
    
};