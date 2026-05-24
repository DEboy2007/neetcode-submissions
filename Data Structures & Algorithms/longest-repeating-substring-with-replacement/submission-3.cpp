class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.length() < 2) return s.length();
        int l = 0;
        unordered_map<char, int> f;
        int maxf = 0;
        int maxLen = 0;
        for (int r = 0; r < s.length(); r++) {
            f[s[r]]++;
            maxf = max(maxf, f[s[r]]);
            while ((r - l + 1) - maxf > k) {
                f[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;

    }
};
