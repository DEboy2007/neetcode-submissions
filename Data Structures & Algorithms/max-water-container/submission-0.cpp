class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxArea = 0;
        while (i < j && i < height.size() && j >= 0) {
            int ar = area(height, i, j);
            if (ar > maxArea) {
                maxArea = ar;
            }
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxArea;
    }

    int area(vector<int>& height, int i, int j) {
        return abs(i - j) * min(height[i], height[j]);
    }
};