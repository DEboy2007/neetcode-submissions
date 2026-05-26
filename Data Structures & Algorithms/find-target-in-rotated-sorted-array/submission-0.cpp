class Solution {
public:
    int search(vector<int>& nums, int target) {
        // logn to find minimum, then logn to search
        int mnIdx = findMin(nums);
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int midIdx = (mid + mnIdx) % nums.size();
            if (nums[midIdx] < target) {
                left = mid + 1;
            } else if (nums[midIdx] > target) {
                right = mid;
            } else {
                return midIdx;
            }
        }
        return -1;
    }

    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size(); // exclusive
        int mn = nums[0];
        int mnIdx = 0;
        while (left < right - 1) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < mn) {
                mn = nums[mid];
                mnIdx = mid;
            }
            if (nums[left] > nums[mid]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return mnIdx;
    }
};
