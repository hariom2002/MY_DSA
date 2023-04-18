class Solution {
public:
    
    vector<vector<string>> res;
    vector<string> curr;
    
    bool isPalindrome(string str)
    {
        for(int i=0;i<=str.size()/2;i++)
            if(str[i]!=str[str.size()-i-1])
                return false;
        return true;
    }
    
    void fnc(string s)
    {
        if(s.size()==0)
        {
            res.push_back(curr);
            return;
                
        }
       
        for(int i=0;i<s.size();i++)
        {
            string leftPart = s.substr(0,i+1);
            if(isPalindrome(leftPart))
            {
                curr.push_back(leftPart);
                fnc(s.substr(i+1));
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        fnc(s);
        return res;
    }
};