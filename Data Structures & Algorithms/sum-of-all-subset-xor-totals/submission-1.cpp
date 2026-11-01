class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sumXOR = 0;
        for (int i = 0; i < pow(2, nums.size()); i++) {
            int thisTotal = 0;
            for (int shift = 0; shift < nums.size(); shift++) {
                if ((i >> shift) & 0b1) {
                    thisTotal = thisTotal ^ nums[shift];
                }
            }
            sumXOR += thisTotal;
        }
        return sumXOR;
        
    }
};