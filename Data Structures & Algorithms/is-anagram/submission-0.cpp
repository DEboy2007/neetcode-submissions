class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        for (char c : t) {
            freq[c]--;
        }
        for (auto &[c, f] : freq) {
            if (f != 0) return false;
        }
        return true;
    }
};
