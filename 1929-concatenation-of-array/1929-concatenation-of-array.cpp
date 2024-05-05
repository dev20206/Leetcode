class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        // Append the elements of nums to ans
        for (int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
        }
        
        // Append the elements of nums again to ans
        for (int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
        }
        
        return ans;
    }
};
