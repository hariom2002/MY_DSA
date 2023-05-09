class Solution
{
public:
    int binarySearch(vector<int> &nums, int low, int high, int x)
    {

        if (high >= low)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == x)
                return mid;
            if (nums[mid] < x)
                return binarySearch(nums, mid + 1, high, x);
            else
                return binarySearch(nums, low, mid - 1, x);
        }
        return -1;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {

        vector<int> res(2, -1);
        int mid = binarySearch(nums, 0, nums.size() - 1, target);
        if (mid == -1)
            return res;

        int r_idx = mid;
        int l_idx = mid;

        while (r_idx + 1 < nums.size() && nums[r_idx + 1] == target)
            r_idx++;

        while (l_idx - 1 >= 0 && nums[l_idx - 1] == target)
            l_idx--;

        res.clear();
        res.push_back(l_idx);
        res.push_back(r_idx);
        return res;
        //  the code ends here
    }
};