class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;
        unordered_map<char, int> target;
        unordered_map<char, int> curr;
        for (char c : s1) {
            target[c]++;
        }
        for (int i = 0; i < s1.length(); i++) {
            curr[s2[i]]++;
        }
        int j = s1.length() - 1;
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            bool check = true;
            for (auto &[c, n] : curr) {
                if (target[c] != n) {
                    check = false;
                    break;
                }
            }
            if (check) return true;
            curr[s2[i]]--;
            j++;
            curr[s2[j]]++;
        }
        return false;
    }
};
