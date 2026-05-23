class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> result(nums.size());
        left[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] = left[i] * right;
            right *= nums[i];
        }
        return result;
    }
};
