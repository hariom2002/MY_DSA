class Solution {
public:
    int trap(vector<int>& height) {
        // optimal approach

        int leftMax = 0;
        int rightMax = 0;

        int l = 0;
        int r = height.size()-1;
        
        int sum = 0;
        

           while(l<=r){
            if(height[l]<= height[r]){
                if(height[l]>leftMax)
                    leftMax = height[l];
                sum+=leftMax-height[l];
                l++;
            }
            else{
                if(height[r]>rightMax)
                    rightMax = height[r];
                sum+=rightMax-height[r];
                r--;
            }
           }
           return sum;
        
    }
};