class Solution {
public:
    
    bool isOperator(string str){
        if(str == "+" || str == "-" || str == "*" || str == "/")
            return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        
        stack<string> st;
        
        for(string s: tokens){
            
            if(!isOperator(s)){
                st.push(s);
            }
            else{
                int a = stoi(st.top());st.pop();
                int b = stoi(st.top());st.pop();
                
                char ch = s[0];
                
                switch(ch){
                    case '+':
                        st.push(to_string(a+b));
                        break;
                    case '-':
                        st.push(to_string(b-a));
                        break;
                    case '*':
                        st.push(to_string(a*b)); 
                        break;
                    
                    default:
                        st.push(to_string(b/a));
                                   
                }
            }
        }
        return stoi(st.top());
        
    }
};