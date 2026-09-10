class Comp {
    public:
        bool operator()(const vector<int>& p1, const vector<int>& p2) const {
            return (p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]);
        }
        
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), Comp());
        int p = points.size() - k;
        for (int i = 0; i < p; i++) points.pop_back();
        return points;
    }
};
