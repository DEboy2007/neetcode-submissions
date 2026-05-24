class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<int> indices(position.size());
        std::iota(indices.begin(), indices.end(), 0);
        // sort by position array
        std::sort(indices.begin(), indices.end(), [&](int i, int j) {
            return position[i] > position[j];
        });
        stack<int> st;
        vector<double> times(indices.size());
        for (int j = 0; j < indices.size(); j++) {
            int i = indices[j];
            times[i] = (target - position[i]) 
            / static_cast<double>(speed[i]);
        }
        for (int j = 0; j < indices.size(); j++) {
            int i = indices[j];
            while (!st.empty() && times[i] <= times[st.top()]) {
                position[i] = position[st.top()];
                speed[i] = speed[st.top()];
                times[i] = times[st.top()];
                st.pop();
            }
            st.push(i);
        }
        return st.size();
        
    }
};
