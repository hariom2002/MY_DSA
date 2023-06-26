class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int high = nums.size() - 1;
        int low = 0;

        int idx = -1;
        // while (high >= low)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
            idx = mid;
        }
        if (target < nums[idx])
            return idx;
        return idx + 1;
    }
};