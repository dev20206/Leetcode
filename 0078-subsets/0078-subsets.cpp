class Solution {
public:

    void recursion(int index, int n, vector<int>&nums, vector<int>&ds , vector<vector<int>>&ans)
    {
        if(index==n)
        {
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[index]);
        recursion(index+1, n, nums,ds,ans);

        ds.pop_back();
        recursion(index+1,n , nums,ds,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = nums.size();
        recursion(0,n,nums,ds,ans);
        return ans;
        
    }
};