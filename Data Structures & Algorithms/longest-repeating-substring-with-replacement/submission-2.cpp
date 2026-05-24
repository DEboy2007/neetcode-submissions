class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.length() < 2) return s.length();
        int i = 0;
        int j = 0;
        unordered_map<char, int> f;
        f[s[0]] = 1;
        int maxLen = 0;
        while (i <= j && j < s.length()) {
            while (i <= j) {
                int total = 0;
                int mx = 0;
                for (auto &[c, n] : f) {
                    total += n;
                    mx = max(mx, n);
                }
                if (total - mx <= k) {
                    break;
                }
                f[s[i]]--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
            f[s[j]]++;
        }
        return maxLen;

    }
};
