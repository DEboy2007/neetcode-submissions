class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.contains(target - nums[i])) {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        
    }
};
