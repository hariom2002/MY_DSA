//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int low = 1;
        long long int high = x;
        
        long long int res = 0;
        
        while(high>=low){
            long long int mid = low+(high-low)/2;
            
            if(mid*mid <= x){
                low = mid+1;
                res = mid;
            }
            else{
                high=mid-1;
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
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends