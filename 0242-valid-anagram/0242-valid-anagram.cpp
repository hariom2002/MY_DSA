class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())return false;
        vector<int> map(26, 0);
        
        for(int i=0;i<s.size();i++){
            map[s[i] - 97]++;
            map[t[i] - 97]--;
        }
             
        for(int i=0;i<26;i++)
            if(map[i] != 0)return false;
        
        return true;
        
    }
};