//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
       long long high = v.size()-1;
       long long low = 0;
       
       int idx = -1;
       
       while(high>=low){
           int mid = low+ (high-low)/2;
           if(v[mid] == x){
            idx = mid; break;
           }
           else if(v[mid] > x)high = mid-1;
           else low=mid+1;
           idx = mid;
       }
       if(idx<=0)return -1;
       return idx;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends