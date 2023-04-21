class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        if(s.length() == 1)return 1;
        int lngst = 0;
        int count=1;
        
        for(int i=1;i<s.length();i++){
            if((s[i] - 'a') == ( s[i-1] - 'a' ) + 1 )
                count++;
            else{
                lngst = (lngst < count)?count:lngst;
                count=1;
            }
                
        }
         lngst = (lngst < count)?count:lngst;
        return lngst;
    }
};