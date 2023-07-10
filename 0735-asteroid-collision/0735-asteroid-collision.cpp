class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int i=0;i<asteroids.size();i++){
            
            if(asteroids[i] > 0 || st.empty()){
                st.push(asteroids[i]);
            }
            else{
               while(st.size() && st.top()>0 &&  st.top() < abs(asteroids[i]))st.pop();
                if(st.size() && st.top() == abs(asteroids[i]))
                    st.pop();
                
                else {
                    if(st.empty() || st.top() <0)
                    st.push(asteroids[i]);
                }
            }
            
            
            
        }
        vector<int> res;
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};