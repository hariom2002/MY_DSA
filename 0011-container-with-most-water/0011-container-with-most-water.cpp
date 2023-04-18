class Solution {
public:
    int res = 0;
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int right =height.size()-1;
        
        while(right > left){
            int area = min(height[left], height[right])*(right - left);
            res = (area > res)? area : res;
            
            if(height[left] > height[right])
                right--;
            else 
                left++;
        }
        return res;
    }
};