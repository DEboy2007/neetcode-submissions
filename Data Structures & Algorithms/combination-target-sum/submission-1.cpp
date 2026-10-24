class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        helper(result, nums, target, 0, {});
        return result;
    }

    void helper(vector<vector<int>>& result, vector<int>& nums, int target, int currSum, vector<int> currVec) {
        if (currSum == target) {
            result.push_back(currVec);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if ((currSum + nums[i]) > target) continue;
            if (!currVec.empty() && nums[i] < currVec.back()) continue;
            vector<int> tempVec = currVec;
            tempVec.push_back(nums[i]);
            helper(result, nums, target, currSum + nums[i], tempVec);
        }
    }
};
