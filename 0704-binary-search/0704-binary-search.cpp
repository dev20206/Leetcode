#include <vector>

class Solution {
private:
    int low;
    int high;

public:
    int search(std::vector<int>& nums, int target, int low, int high) {
        if (low > high) {
            // Base case: target not found
            return -1;
        }

        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            // Target found
            return mid;
        } else if (target > nums[mid]) {
            // Search in the right half
            return search(nums, target, mid + 1, high);
        } else {
            // Search in the left half
            return search(nums, target, low, mid - 1);
        }
    }

    // Overloaded search function with default values for low and high
    int search(std::vector<int>& nums, int target) {
        low = 0;
        high = nums.size() - 1;
        return search(nums, target, low, high);
    }
};
