class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = 2^31 - 1;
        // multi source BFS, check if new distance value is <= curr distance value
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }
        vector<pair<int, int>> DIRS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        while (!q.empty()) {
            pair<int, int> coords = q.front(); q.pop();
            visited[coords.first][coords.second] = true;
            int curr = grid[coords.first][coords.second];
            for (pair<int, int> d : DIRS) {
                pair<int, int> nCoords = {coords.first + d.first, coords.second + d.second};
                int r = nCoords.first;
                int c = nCoords.second;
                if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == -1) continue;
                if (grid[r][c] > grid[coords.first][coords.second] + 1) {
                    grid[r][c] = grid[coords.first][coords.second] + 1;
                }
                if (!visited[nCoords.first][nCoords.second]) q.push(nCoords);
            }
        }
        
    }
};
