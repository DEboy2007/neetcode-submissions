class KthLargest {
private:
    // store a min heap and max heap of k elements
    // track smallest of those k elements
    // when a number is added that is bigger than smallest, pop from the  
    int k;
    int smallest;
    vector<int> nums; // decreasing

public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int i : nums) {
            add(i);
        }
    }
    
    int add(int val) {
        if (nums.size() < k) {
            auto it = lower_bound(nums.begin(), nums.end(), val, greater<int>());
            nums.insert(it, val);
        } else {
            if (val > nums.back()) {
                nums.pop_back();
                auto it = lower_bound(nums.begin(), nums.end(), val, greater<int>());
                nums.insert(it, val);
            }
        }
        return nums.back();
    }
};
