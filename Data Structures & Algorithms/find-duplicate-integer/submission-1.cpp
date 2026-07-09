class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int curr = abs(nums[i]);
            bool seen = nums[curr] < 1;
            if (seen) return curr;
            nums[curr] = -nums[curr];
        }
        return 0;
    }
};
