class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() * matrix[0].size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            auto [r, c] = convert(matrix, mid);
            if (matrix[r][c] < target) {
                left = mid + 1;
            } else if (matrix[r][c] > target) {
                right = mid;
            } else {
                return true;
            }
        }
        return false;
    }

    pair<int, int> convert(vector<vector<int>>& matrix, int oneD) {
        return {oneD / matrix[0].size(), oneD % matrix[0].size()};
    }
};
