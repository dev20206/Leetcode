class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int left = 0;
        int right = x;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (long(mid) * mid == x) {
                return mid;  // Found the exact square root
            }
            else if (long(mid) * mid < x) {
                left = mid + 1;  // Move to the right half
            }
            else {
                right = mid - 1;  // Move to the left half
            }
        }

        // Return the floor of the square root
        return right;
    }
};
