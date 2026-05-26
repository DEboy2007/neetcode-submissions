class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minK = 1;
        // if k = max(piles), need piles.size() hours to finish
        int maxK = *max_element(piles.begin(), piles.end());
        while (minK < maxK) {
            int midK = minK + (maxK - minK) / 2;
            int time = calcTime(piles, midK);
            if (time <= h) {
                maxK = midK;
            } else {
                minK = midK + 1;
            }
        }
        return minK;

    }
    
    int calcTime(vector<int>& piles, int k) {
        int time = 0;
        for (int b : piles) {
            time += ceil(static_cast<double>(b) / k);
        }
        return time;
    }
};
