class Solution {
public:
    bool isPossible(vector<int>& piles, int k, int h){
        int n = piles.size();
        double hrs = 0;
        for(int i = 0; i<n; i++){
            hrs += ceil((double)(piles[i]) / (double)(k));
            // if(hr>h)return false;
        }
        return hrs<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 0, end = *max_element(piles.begin(), piles.end());
        int ans =  end;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isPossible(piles, mid, h)){
                end = mid-1;
            }
            else start = mid+1;
        }
        return start;
    }
};