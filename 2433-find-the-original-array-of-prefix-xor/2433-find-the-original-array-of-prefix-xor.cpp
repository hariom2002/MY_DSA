class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        int ptr = pref[0];
        vector<int > res;
        res.push_back(pref[0]);
        for(int i=1;i<pref.size();i++){
            int temp = pref[i] ^ ptr;
            res.push_back(temp);
            ptr = pref[i];
        }
        return res;
    }
};