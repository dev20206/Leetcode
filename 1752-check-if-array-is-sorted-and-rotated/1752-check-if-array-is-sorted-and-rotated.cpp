#include <vector>

class Solution {
public:
    bool check(std::vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            std::vector<int> rotated(n);
            
            // Create the rotated array
            for (int j = 0; j < n; j++) {
                rotated[j] = nums[(j + i) % n];
            }
            
            // Check if the rotated array is sorted
            bool sorted = true;
            for (int k = 1; k < n; k++) {
                if (rotated[k] < rotated[k - 1]) {
                    sorted = false;
                    break;
                }
            }
            
            // If the rotated array is sorted, return true
            if (sorted) {
                return true;
            }
        }
        
        // If no rotation resulted in a sorted array, return false
        return false;
    }
};
