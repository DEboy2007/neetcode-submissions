class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> result;
        unordered_map<int, int> s;
        for (int i = 0; i < nums.size(); i++) {
            s[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int k = 0 - nums[i] - nums[j];
                if (s.contains(k) && s[k] != i && s[k] != j) {
                    vector<int> ts = {nums[i], nums[j], k};
                    sort(ts.begin(), ts.end());
                    result.insert(ts);
                }
            }
        }
        vector<vector<int>> res;
        for (auto &v : result) {
            res.push_back(move(v));
        }
        return res;
    }
};
