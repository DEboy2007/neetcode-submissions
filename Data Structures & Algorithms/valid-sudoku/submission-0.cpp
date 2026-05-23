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
                int b = classifyBox(i, j);
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

    int classifyBox(int i, int j) {
        if ((0 <= i && i <= 2) && (0 <= j && j <= 2)) return 0;
        if ((3 <= i && i <= 5) && (0 <= j && j <= 2)) return 1;
        if ((6 <= i && i <= 8) && (0 <= j && j <= 2)) return 2;

        if ((0 <= i && i <= 2) && (3 <= j && j <= 5)) return 3;
        if ((3 <= i && i <= 5) && (3 <= j && j <= 5)) return 4;
        if ((6 <= i && i <= 8) && (3 <= j && j <= 5)) return 5;

        if ((0 <= i && i <= 2) && (6 <= j && j <= 8)) return 6;
        if ((3 <= i && i <= 5) && (6 <= j && j <= 8)) return 7;
        return 8;
    }
};
