class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<pair<int, int>> q;
        vector<pair<int, int>> DIRS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool min0 = true;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push_back({i, j});
                }
                if (grid[i][j] == 1) {
                    min0 = false;
                }
            }
        }
        if (min0) return 0;
        if (q.empty()) return -1;
        int mins = 0;
        pair<int, int> lastMinEnd = q.back();
        while (!q.empty()) {
            pair<int, int> curr = q.front(); q.pop_front();
            int i = curr.first;
            int j = curr.second;
            for (auto &[d1, d2] : DIRS) {
                int x = i + d1;
                int y = j + d2;
                if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) continue;
                if (grid[x][y] != 1) continue;
                grid[x][y] = 2;
                q.push_back({x, y});
            }
            if (curr == lastMinEnd && !q.empty()) {
                mins++;
                lastMinEnd = q.back();
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return mins;
    }
};
