#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                // The peak is on the left side (including mid)
                right = mid;
            } else {
                // The peak is on the right side (excluding mid)
                left = mid + 1;
            }
        }
        
        // left will be the index of the peak element
        return left;
    }
};
