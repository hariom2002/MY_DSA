class Solution {
public:

    stack<int> stack;

    bool isValid(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i] == '{' || s[i] == '[')
                stack.push(s[i]);
            else{
                if(stack.empty())
                    return false;

                char c = s[i];char s = stack.top();
                stack.pop();
                if(c == ')' && s == '(') continue;
                if(c == ']' && s == '[') continue;
                if(c == '}' && s == '{') continue;

                else return false;
            }

        }
        if(stack.empty())return true;
        return false;
    }
};