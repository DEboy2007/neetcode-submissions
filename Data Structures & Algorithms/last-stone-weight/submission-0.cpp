class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();
            // invariant: x <= y
            if (x < y) {
                pq.push(y - x);
            }
        }
        if (pq.empty()) return 0;
        return pq.top();
        
    }
};
