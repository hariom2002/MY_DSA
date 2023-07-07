class Solution {
public:
    
    long long totalHrs(vector<int> &piles, int k){
        long long hrs = 0;
        for(int i=0;i<piles.size();i++){
            hrs += ceil((double)(piles[i]) / (double)(k));  
        }
        // cout<<hrs<<endl;
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
//         applying binary search on serach space;
        int maxx = *max_element(piles.begin(), piles.end());
        
        int low =1;
        int high = maxx;
        
        int res = INT_MAX;
        
        while(high>=low){
            
            int mid = low+(high-low)/2;
            long long temp_hrs = totalHrs(piles, mid);
            if(temp_hrs <=h){
                res = mid;
                high = mid-1;
            }
            else low=mid+1;
            
        }
        return res;
        
    }
};