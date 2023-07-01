//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        
        // using bit manipulation
        
        int xr = 0;
        for(int i=0;i<n;i++){
            xr ^= arr[i];
            xr ^= (i+1);
        }
        
        int rightSetBit = 0;
        
        while(1){
            if((xr & (1<<rightSetBit)) != 0)
                break;
            rightSetBit++;
        }
        
        int zero = 0;
        int one = 0;
        
        for(int i=0;i<n;i++){
            
            if((arr[i] & (1<<rightSetBit)) != 0){
                one ^= arr[i];
            }
            else
                zero ^= arr[i];
        }
        for(int i=1;i<=n;i++){
            
            if((i & (1<<rightSetBit)) != 0){
                one ^= i;
            }
            else
                zero ^= i;
        }
        // let's check which number is repeating and which is duplicate
        
        int dup = -1;
        for(int i=0;i<=n;i++){
            
            if(arr[i] == one){
                dup = one;
                break;
            }
        }
        if(dup == -1){
            return {zero, one};
        }
        return {one, zero};
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends