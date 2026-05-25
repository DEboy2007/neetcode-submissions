class Solution {
public:
    string minWindow(string s, string t) {
        // sliding window
        // increase j if we need characters, reduce i to remove characters
        unordered_map<char, int> tF;
        unordered_map<char, int> cF;
        for (char c : t) {
            tF[c]++;
        }

        int i = 0;
        int shortest = INT_MAX;
        int shortestI = 0;

        for (int j = 0; j < s.length(); j++) {
            cF[s[j]]++;
            bool origValid = valid(tF, cF);
            while (i <= j && valid(tF, cF)) {
                // while too many chars, shrink substr
                cF[s[i]]--;
                i++;
            }
            if (origValid) {
                i--;
                cF[s[i]]++;
                shortest = min(shortest, j - i + 1);
                if (shortest == j - i + 1) shortestI = i;
            }
        }
        
        if (shortest == INT_MAX) return "";
        return s.substr(shortestI, shortest);
    }

    bool valid(unordered_map<char, int> &tF, unordered_map<char, int> &cF) {
        for (auto &[c, n] : tF) {
            if (cF[c] < n) {
                // still need chars
                return false;
            }
        }
        return true;
    }
};
