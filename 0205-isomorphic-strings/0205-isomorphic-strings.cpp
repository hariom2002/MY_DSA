class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        return helper(s, t) && helper(t,s);
    }
    bool helper(string s, string t){
        map<char, char> map;
        
        for(int i=0;i<s.size();i++){
            if(map.find(s[i]) != map.end() && map[s[i]] != t[i])
                return false;
            
            map[s[i]] = t[i];

        }
        return true;
    }
};