//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    
     int precedence(char ch)
    {
        if(ch=='^') return 3;
        else if(ch=='/' || ch=='*') return 2;
        else if(ch=='+' || ch=='-') return 1;
        else return -1;
    }
    
    bool isChar(char c)
    {
        if(c=='/' || c=='*'|| c=='+' || c=='-' || c==')' || c=='(' || c=='^') return false;
        else return true;
    }
    
    
    string infixToPostfix(string s) {
        // Your code here
        stack<char> sigma;
        
        string ans="";
        
        for(char ch: s)
        {
            if(isChar(ch))
            {
                ans+=ch;   
            }
            else if(ch=='('){
                sigma.push(ch);
            }
            else if(ch==')')
            {
                while(sigma.top()!='(')
                {
                    ans+=sigma.top();
                    sigma.pop();
                }
                sigma.pop();
            }
            else
            {
                while(!sigma.empty() && precedence(ch)<=precedence(sigma.top()))
                {
                    ans+=sigma.top();
                    sigma.pop();
                }
                sigma.push(ch);
            }
        }
        
        while(!sigma.empty())
        {
            ans+=sigma.top();
            sigma.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends