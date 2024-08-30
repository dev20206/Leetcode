#include <vector>
using namespace std;

class Solution {
public:
    void recursion(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, int n, int k, int sum, int index) {
        // Base case: if the combination size is k and the sum equals n
        if (ds.size() == k && sum == n) {
            ans.push_back(ds);
            return;
        }

        // Early termination if size exceeds k or sum exceeds n
        if (ds.size() > k || sum > n) {
            return;
        }

        // Iterate over the remaining numbers starting from the current index
        for (int i = index; i < nums.size(); i++) {
            ds.push_back(nums[i]);  // Include the current number
            recursion(nums, ds, ans, n, k, sum + nums[i], i + 1);  // Move to the next number
            ds.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums(9);
        for (int i = 0; i < 9; i++) {
            nums[i] = i + 1;  // Initialize nums with values 1 to 9
        }

        vector<int> ds;
        vector<vector<int>> ans;
        recursion(nums, ds, ans, n, k, 0, 0);  // Start recursion with initial values
        return ans;
    }
};
