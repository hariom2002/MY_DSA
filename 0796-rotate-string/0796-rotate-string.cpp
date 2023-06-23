class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.size() != goal.size())return false;
        
        string str = s + s;
        char ch = goal[0];
        
        // int idx = 0;
        // for(int i=0;i<str.size();i++){
        //     if(ch == str[i]){
        //         int j = 0;
        //         while(goal[j] == str[i]){
        //             j++; i++;
        //         }
        //         idx = j;
        //     }
        // }
        // if(idx >= goal.size())return true;
        // return false;
        
        if(str.find(goal) != string::npos) return true;
        return false;
    }
};