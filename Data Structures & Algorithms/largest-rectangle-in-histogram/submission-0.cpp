class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // increasing
        int largest = 0;
        for (int i = 0; i <= heights.size(); i++) {
            int currHeight = (i == heights.size()) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] >= currHeight) {
                int popped = st.top(); st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                largest = max(largest, width * heights[popped]);
            }
            st.push(i);
        }
        return largest;
    }
};
