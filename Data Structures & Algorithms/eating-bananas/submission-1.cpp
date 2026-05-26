class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minK = 1;
        // if k = max(piles), need piles.size() hours to finish
        int maxK = 0;
        for (int b : piles) {
            maxK = max(maxK, b);
        }
        int bestK = maxK;
        while (minK < maxK) {
            int midK = minK + (maxK - minK) / 2;
            int time = calcTime(piles, midK);
            if (time <= h) {
                bestK = min(bestK, midK);
                maxK = midK;
            } else {
                minK = midK + 1;
            }
        }
        return bestK;

    }
    
    int calcTime(vector<int>& piles, int k) {
        int time = 0;
        for (int b : piles) {
            time += ceil(static_cast<double>(b) / k);
        }
        return time;
    }
};
