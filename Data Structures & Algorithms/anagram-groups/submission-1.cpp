class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> fingerprint(26, 0);
            for (int j = 0; j < strs[i].length(); j++) {
                fingerprint[strs[i][j] - 'a']++;
            }
            mp[fingerprint].push_back(strs[i]);
        }
        vector<vector<string>> result(mp.size());
        int i = 0;
        for (auto &[fingerprint, strings] : mp) {
            result[i] = move(strings);
            i++;
        }
        return result;
    }
};
