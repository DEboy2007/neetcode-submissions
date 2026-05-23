class Solution {
public:

    string encode(vector<string>& strs) {
        string lengths;
        string concat;
        for (string s : strs) {
            lengths += to_string(s.length());
            lengths += '#';
            concat += s;
        }
        return lengths + '@' + concat;
    }

    vector<string> decode(string s) {
        vector<string> result;
        vector<int> lengths;
        int i = 0;
        int currNum = 0;
        while (i < s.length() && s[i] != '@') {
            if (s[i] == '#') {
                lengths.push_back(currNum);
                currNum = 0;
            } else {
                currNum = currNum * 10 + (s[i] - '0');
            }
            i++;
        }
        i++;
        for (int l : lengths) {
            string ts;
            for (int j = 0; j < l; j++) {
                ts += s[i];
                i++;
            }
            result.push_back(ts);
        }
        return result;

    }
};
