#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        
        int operations = 0;
        for (int i = 31; i >= 0; --i) {
            int kBit = (k >> i) & 1; // Get i-th bit of k
            int xorSumBit = (xorSum >> i) & 1; // Get i-th bit of xorSum
            if (xorSumBit != kBit) {
                ++operations;
            }
        }
        
        return operations;
    }
};
