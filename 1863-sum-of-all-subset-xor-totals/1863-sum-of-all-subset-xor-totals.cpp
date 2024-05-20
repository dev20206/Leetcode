class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int totalXorSum = 0;
        int totalSubsets = 1 << n; // Total number of subsets is 2^n
        
        // Iterate over all possible subsets
        for (int i = 0; i < totalSubsets; i++) {
            int currentXor = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    currentXor ^= nums[j];
                }
            }
            totalXorSum += currentXor;
        }
        
        return totalXorSum;
    }
};
