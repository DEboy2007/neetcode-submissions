class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> boxes(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char currC = board[i][j];
                if (!isdigit(currC)) continue;
                int curr = currC - '0';
                int b = (i / 3) * 3 + (j / 3);
                if (rows[i].contains(curr)) return false;
                if (cols[j].contains(curr)) return false;
                if (boxes[b].contains(curr)) return false;
                rows[i].insert(curr);
                cols[j].insert(curr);
                boxes[b].insert(curr);
            }
        }
        return true;
    }
};
