class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int j = values.size() - 1;
        int i = values.size() - 2;
        int currMax = values[i] + values[j] - 1;
        for (i = values.size() - 3; i >= 0; i--) {
            int newJCandidate = i + 1;
            if (values[i] + values[newJCandidate] - 1 > values[i] + values[j] - (j - i)) {
                j = newJCandidate;
            }
            currMax = max(currMax, values[i] + values[j] - (j - i));
            
        }
        return currMax;

    }
};
