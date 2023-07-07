//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int low = 0;
	    int high  = n-1;
	    int idx;
	    int minn = INT_MAX;
	    
	    while(high>=low){
	        int mid = low+(high-low)/2;
	        
	       // if(arr[mid] >= arr[low] && arr[mid]<=arr[high])return 0;
	        
	        if(arr[mid] >= arr[low]){
	            if(minn >arr[low]){
	                minn = arr[low];
	                idx = low;
	            }
	            low=mid+1;
	        }
	        else{
	            if(minn > arr[mid]){
	                minn = arr[mid];
	                idx = mid;
	            }
	            high = mid-1;
	        }
	    }
	   return idx;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends