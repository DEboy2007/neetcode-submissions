class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st; // decreasing
        int vol = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[st.top()] < height[i]) {
                int right = i;
                int mid = st.top();
                st.pop();
                if (st.empty()) break;
                int left = st.top();
                int h = min(height[right], height[left]) - height[mid];
                int w = right - left - 1;
                vol += h * w;
            }
            st.push(i);
        }
        return vol;
    }
};
