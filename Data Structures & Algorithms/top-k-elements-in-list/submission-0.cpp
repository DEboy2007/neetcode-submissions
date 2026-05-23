class Solution {
public:

    struct Comp {
        bool operator()(pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // hashmap for frequency of each element
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
        for (int i : nums) {
            freq[i]++;
        }
        for (auto & p : freq) {
            pq.push(p);
        }
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
        
    }
};
