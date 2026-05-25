class Solution {
public:
    string minWindow(string s, string t) {
        // sliding window
        // increase j if we need characters, reduce i to remove characters
        if (s.size() == 0 || t.size() == 0) return "";
        unordered_map<char, int> tF;
        unordered_map<char, int> cF;
        for (char c : t) {
            tF[c]++;
        }
        int needed = tF.size();
        int satisfied = 0;

        int i = 0;
        int shortest = INT_MAX;
        int shortestI = 0;

        for (int j = 0; j < s.size(); j++) {
            cF[s[j]]++;
            if (tF.contains(s[j]) && tF[s[j]] == cF[s[j]]) satisfied++;
            while (i <= j && satisfied == needed) {
                if (j - i + 1 < shortest) {
                    shortest = j - i + 1;
                    shortestI = i;
                }
                cF[s[i]]--;
                if (tF.contains(s[i]) && cF[s[i]] < tF[s[i]]) satisfied--;
                i++;
            }
        }
        
        return (shortest == INT_MAX) ? "" : s.substr(shortestI, shortest);
    }
};
