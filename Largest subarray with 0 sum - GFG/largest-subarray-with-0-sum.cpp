//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int N)
    {   
         map<int, int> map;
         int k  =0;
       int res = 0;
       
       int sum = 0;
       
       for(int i = 0;i<N;i++){
           
           sum+=A[i];
           
           if(map.find(sum) == map.end())
            map[sum]=i;
           
           if(sum == k)
                res = max(res, i + 1);
                
            if(map.find(sum-k) != map.end()){
                res = max(res, i - map.at(sum-k));
            }
           
       }
       return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends