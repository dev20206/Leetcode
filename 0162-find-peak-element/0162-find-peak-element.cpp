#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        // Handle edge cases
        if (n == 1) return 0;
        if (n == 2) return nums[0] > nums[1] ? 0 : 1;
        
        // Check for peak element
        for (int i = 0; i < n; ++i) {
            // If the current element is the first element
            if (i == 0 && nums[i] > nums[i + 1]) return i;
            // If the current element is the last element
            if (i == n - 1 && nums[i] > nums[i - 1]) return i;
            // If the current element is greater than its neighbors
            if (i > 0 && i < n - 1 && nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
        }
        
        return -1;  // This line will never be reached because there is always at least one peak element
    }
};
