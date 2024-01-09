class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ret(2);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = nums[i] + nums[j];
                if (sum == target) {
                    ret[0] = i;
                    ret[1] = j;
                    return ret; // Found the pair, return immediately
                }
            }
        }

        // If no pair is found, return an empty vector
        return ret;
    }
};
