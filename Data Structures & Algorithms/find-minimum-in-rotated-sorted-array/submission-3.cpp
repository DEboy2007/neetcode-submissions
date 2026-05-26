class Solution {
public:
    int findMin(vector<int> &nums) {
        // smallest element is local minimum (bigger element on left and right)
        // binary search on n
        // if left is bigger than mid, jump to min happened somewhere in left interval
        // if left is smaller than mid, jump to min did not happen in left interval (so go right)
        int left = 0;
        int right = nums.size(); // exclusive
        int mn = nums[0];
        while (left < right - 1) {
            int mid = left + (right - left) / 2;
            mn = min(mn, nums[mid]);
            if (nums[left] > nums[mid]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return mn;
    }
};
