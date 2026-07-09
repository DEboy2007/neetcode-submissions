class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> seen;
        for (int i : nums) {
            if (seen.contains(i)) {
                return i;
            }
            seen.insert(i);
        }
    }
};
