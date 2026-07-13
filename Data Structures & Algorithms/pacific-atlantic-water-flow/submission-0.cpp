class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.size() == 0) return {};
        // 0 if neither, 1 if pacific, 2 if atlantic, 3 if both
        vector<vector<int>> flow(heights.size(), vector<int>(heights[0].size(), 0));
        vector<pair<int, int>> DIRS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> res;
        // pacific first, then atlantic
        queue<pair<int, int>> q;
        for (int i = 0; i < heights.size(); i++) {
            q.push({i, 0});
            flow[i][0] = 1;
        }
        for (int j = 0; j < heights[0].size(); j++) {
            q.push({0, j});
            flow[0][j] = 1;
        }
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            int curr = heights[x][y];
            for (auto &[d1, d2] : DIRS) {
                int nx = x + d1;
                int ny = y + d2;
                if (nx < 0 || ny < 0 || nx >= heights.size() || ny >= heights[0].size()) continue;
                if (flow[nx][ny] != 0) continue; // visited
                if (heights[nx][ny] < curr) continue;
                flow[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
        for (int i = 0; i < heights.size(); i++) {
            q.push({i, heights[0].size() - 1});
            if (flow[i][heights[0].size() - 1] == 1) {
                flow[i][heights[0].size() - 1] = 3;
                res.push_back({i, (int) heights[0].size() - 1});
            } else {
                flow[i][heights[0].size() - 1] = 2;
            }
        }
        for (int j = 0; j < heights[0].size(); j++) {
            q.push({heights.size() - 1, j});
            if (flow[heights.size() - 1][j] == 1) {
                flow[heights.size() - 1][j] = 3;
                res.push_back({(int) heights.size() - 1, j});
            } else {
                flow[heights.size() - 1][j] = 2;
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            int curr = heights[x][y];
            for (auto &[d1, d2] : DIRS) {
                int nx = x + d1;
                int ny = y + d2;
                if (nx < 0 || ny < 0 || nx >= heights.size() || ny >= heights[0].size()) continue;
                if (flow[nx][ny] != 0 && flow[nx][ny] != 1) continue; // visited
                if (heights[nx][ny] < curr) continue;
                if (flow[nx][ny] == 1) {
                    flow[nx][ny] = 3;
                    res.push_back({nx, ny});
                } else {
                    flow[nx][ny] = 2;
                }
                q.push({nx, ny});
            }
        }
        return res;
        
    }
};
