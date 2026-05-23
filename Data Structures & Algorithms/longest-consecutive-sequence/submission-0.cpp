class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_map<int, int> mp;
        for (int n : nums) {
            if (mp[n] == 0) {
                mp[n] = mp[n - 1] + mp[n + 1] + 1;
                mp[n - mp[n - 1]] = mp[n];
                mp[n + mp[n + 1]] = mp[n];
                longest = max(longest, mp[n]);
            }
        }
        return longest;
        
    }
};
