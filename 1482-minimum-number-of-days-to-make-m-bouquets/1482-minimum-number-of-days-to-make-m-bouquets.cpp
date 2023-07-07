class Solution {
public:
    
    int helper(vector<int> arr, int mid, int m, int k){
        int bq = 0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]-mid <= 0)arr[i] = 0;
            else arr[i]-=mid;
        }
        int cnt = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] != 0){
                cnt=0;
                continue;
            }
            if(arr[i]== 0)cnt++;
            if(cnt==k){
               bq++;
                cnt=0;
                continue;
            }
        }
        // cout<<bq<<endl;
        return bq;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        // long long ttlflwr = k*m;
        // if(ttlflwr > n)return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        int res = INT_MAX;
        
        while(high>=low){
            int mid = low+(high-low)/2;
            
            if(helper(bloomDay, mid, m, k) >= m){
                res=min(res, mid);
                high=mid-1;
            }
            else{
                 low=mid+1;
            }
        }
        return res==INT_MAX?-1:res;
    }
};