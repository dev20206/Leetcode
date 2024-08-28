#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void recursion(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        ans.push_back(ds);
        
        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates to ensure unique subsets
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }
            ds.push_back(nums[i]);
            recursion(i + 1, nums, ds, ans);  // Move to the next index for recursion
            ds.pop_back();  // Backtrack to explore other subsets
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        recursion(0, nums, ds, ans);
        return ans;
    }
};
