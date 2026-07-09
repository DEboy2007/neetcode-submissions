class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int> path;
        queue<int> q;
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int done = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            path.push_back(curr);
            done++;
            for (auto n : adj[curr]) {
                indegree[n]--;
                if (indegree[n] == 0) {
                    q.push(n);
                }
            }
        }

        if (done != numCourses) return {};
        return path;
        
    }
};
