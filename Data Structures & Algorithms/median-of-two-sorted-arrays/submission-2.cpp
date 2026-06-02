class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int half = (nums1.size() + nums2.size() + 1) / 2;
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int minX = 0; // none from nums1
        int maxX = nums1.size(); // all from nums1
        while (minX <= maxX) {
            int x = minX + (maxX - minX) / 2;
            int aLeftPartitionMax = (x == 0) ? INT_MIN : nums1[x - 1];
            int bLeftPartitionMax = (half - x == 0) ? INT_MIN : nums2[half - x - 1];
            int aRightPartitionMin = (x == nums1.size()) ? INT_MAX : nums1[x];
            int bRightPartitionMin = (half - x == nums2.size()) ? INT_MAX : nums2[half - x];
            if (aLeftPartitionMax > bRightPartitionMin) {
                // need more elements from b, so lower x
                maxX = x - 1;
            } else if (bLeftPartitionMax > aRightPartitionMin) {
                // need more elements from a, so increase x
                minX = x + 1;
            } else {
                // valid median, return
                return ((nums1.size() + nums2.size()) % 2 == 0) ? (double) (max(aLeftPartitionMax, bLeftPartitionMax) + min(aRightPartitionMin, bRightPartitionMin)) / 2 : max(aLeftPartitionMax, bLeftPartitionMax);
            }
        }
        return 0;
        
        
    }
};
