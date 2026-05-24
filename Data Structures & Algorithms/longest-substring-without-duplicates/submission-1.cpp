class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();
        unordered_set<char> chars;
        int i = 0;
        int j = 1;
        int maxLength = 1;
        chars.insert(s[0]);
        while (i < j && j < s.length()) {
            while (i < j && chars.contains(s[j])) {
                chars.erase(s[i]);
                i++;
            }
            chars.insert(s[j]);
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        return maxLength;
    }
};
