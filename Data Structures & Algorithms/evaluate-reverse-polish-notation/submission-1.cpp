class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        stack<int> st;
        for (string &s : tokens) {
            if (s == "+") {
                int one = st.top(); st.pop();
                int two = st.top(); st.pop();
                st.push(two + one);
            } else if (s == "-") {
                int one = st.top(); st.pop();
                int two = st.top(); st.pop();
                st.push(two - one);
            } else if (s == "*") {
                int one = st.top(); st.pop();
                int two = st.top(); st.pop();
                st.push(two * one);
            } else if (s == "/") {
                int one = st.top(); st.pop();
                int two = st.top(); st.pop();
                st.push(two / one);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
