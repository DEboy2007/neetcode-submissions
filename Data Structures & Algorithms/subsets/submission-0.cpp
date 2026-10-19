class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        // each possible 2^n bit number in binary being the elements taken
        for (int i = 0; i < pow(2, n); i++) {
            vector<int> curr;
            for (int shift = 0; shift < n; shift++) {
                if ((i >> shift) & 0x1) {
                    curr.push_back(nums[shift]);
                }
            }
            result.push_back(curr);
        }
        return result;
    }
};
