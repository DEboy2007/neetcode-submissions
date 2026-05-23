class MinStack {
private:
    vector<int> st;
    map<int, int> freq;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        freq[val]++;
    }
    
    void pop() {
        int val = top();
        st.pop_back();
        freq[val]--;
        if (freq[val] == 0) {
            freq.erase(val);
        }
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return freq.begin()->first;
    }
};
