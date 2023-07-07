//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool canPlaceCows(vector<int> &stalls, int k, int dist){
        
        int cows = 1;
        int prev = stalls[0];
        
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-prev >= dist){
                cows++;
                prev = stalls[i];
            }
        }
        if(cows >= k)return true;
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
         // Write your code here
         sort(stalls.begin(), stalls.end());
         
         int low = 1;
         int high = *max_element(stalls.begin(), stalls.end()) - *min_element(stalls.begin(), stalls.end());
         int res = 1;
         
         while(high>=low){
             
             int mid = low+(high-low)/2;
             
             if(canPlaceCows(stalls, k, mid)){
                 res = mid;
                 low=mid+1;
             }
             else high=mid-1;
         }
         
         return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends