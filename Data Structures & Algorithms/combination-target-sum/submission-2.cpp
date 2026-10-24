class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> currVec;
        helper(result, nums, 0, target, currVec);
        return result;
    }

    void helper(vector<vector<int>>& result, vector<int>& nums, int start, int remaining, vector<int>& currVec) {
        if (remaining == 0) {
            result.push_back(currVec);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (nums[i] > remaining) break;
            currVec.push_back(nums[i]);
            helper(result, nums, i, remaining - nums[i], currVec);
            currVec.pop_back();
        }
    }
};
