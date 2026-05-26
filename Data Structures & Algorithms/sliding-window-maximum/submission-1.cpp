class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> max; // decreasing
        vector<int> result(nums.size() - k + 1);
        for (int i = 0; i < k; i++) {
            // keep max element in front of queue
            while (!max.empty() && nums[i] > nums[max.back()]) {
                max.pop_back();
            }
            max.push_back(i);
        }        
        for (int i = 0; i <= nums.size() - k; i++) {
            result[i] = nums[max.front()];
            if (i != nums.size() - k) {
                if (nums[i] == nums[max.front()]) {
                    // if dropping max element
                    max.pop_front();
                }
                while (!max.empty() && nums[i + k] > nums[max.back()]) {
                    max.pop_back();
                }
                max.push_back(i + k);
            }
        }
        return result;
    }
};
