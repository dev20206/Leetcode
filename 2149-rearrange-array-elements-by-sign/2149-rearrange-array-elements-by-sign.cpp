class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
       int poshead=0;
        int neghead=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                ans[poshead]=nums[i];
                poshead=poshead+2;
            }
            if(nums[i]<0)
            {
                ans[neghead]=nums[i];
                neghead=neghead+2;
            }
        }
        return ans;
    }
};
