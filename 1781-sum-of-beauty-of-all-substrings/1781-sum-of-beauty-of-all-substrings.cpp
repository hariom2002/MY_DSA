class Solution {
public:
    int beautySum(string s) {
        
        int res = 0;
        
        for(auto i =0;i<s.size();i++){
            int cnt[26]={0}, max_f = 0, min_f = 0;
            
            for(auto j=i;j<s.size();j++){
                
                int idx = s[j] - 'a';
                max_f = max(max_f, ++cnt[idx]);
                
                if (min_f >= cnt[idx] - 1) {
                min_f = cnt[idx];
                for (int k = 0; k < 26; ++k)
//                     to remove the zero minimum from the answer
                    min_f = min(min_f, cnt[k] == 0 ? INT_MAX : cnt[k]);
            }
                 res += max_f - min_f;
            }
            
        }
        return res;
    }
};