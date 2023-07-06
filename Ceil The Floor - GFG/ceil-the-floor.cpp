//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
   
   int fl = INT_MAX;
   int cl = -1;
   
   for(int i=0;i<n;i++){
       
       if(arr[i] == x)return {x,x};
       if(arr[i] < x && arr[i] > cl)cl= arr[i];
       if(arr[i] > x && arr[i] < fl)fl= arr[i];
   }
   if(fl== INT_MAX)fl = -1;
   return {cl,fl};
}