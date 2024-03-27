class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN;
        int currentProduct = 1;

        // Traverse the array from left to right
        for (int i = 0; i < nums.size(); i++) {
            // Update the current product
            currentProduct *= nums[i];
            // Update the maximum product seen so far
            maxProduct = max(maxProduct, currentProduct);

            // Reset the current product if it becomes 0
            if (currentProduct == 0) {
                currentProduct = 1;
            }
        }

        // Reset the current product
        currentProduct = 1;

        // Traverse the array from right to left
        for (int i = nums.size() - 1; i >= 0; i--) {
            // Update the current product
            currentProduct *= nums[i];
            // Update the maximum product seen so far
            maxProduct = max(maxProduct, currentProduct);

            // Reset the current product if it becomes 0
            if (currentProduct == 0) {
                currentProduct = 1;
            }
        }

        return maxProduct;
    }
};
