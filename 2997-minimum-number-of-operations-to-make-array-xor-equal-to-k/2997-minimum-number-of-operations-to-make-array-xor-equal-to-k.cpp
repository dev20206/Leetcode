#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        
        // Convert k to binary representation
        bitset<32> kBinary(k);
        
        // Convert xorSum to binary representation
        bitset<32> xorSumBinary(xorSum);
        
        int operations = 0;
        for (int i = 31; i >= 0; --i) {
            if (xorSumBinary[i] != kBinary[i]) {
                ++operations;
            }
        }
        
        return operations;
    }
};
