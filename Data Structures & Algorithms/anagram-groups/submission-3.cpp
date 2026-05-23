class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> fingerprint(26, 0);
            for (int j = 0; j < strs[i].length(); j++) {
                fingerprint[strs[i][j] - 'a']++;
            }
            string key;
            for (int f : fingerprint) {
                key += to_string(f);
                key += "#";
            }
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for (auto &p : mp) {
            result.push_back(p.second);
        }
        return result;
    }
};
