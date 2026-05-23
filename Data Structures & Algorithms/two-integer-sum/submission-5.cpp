class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            int j = target - nums[i];
            if (indices.contains(j)) {
                return {indices[j], i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};
