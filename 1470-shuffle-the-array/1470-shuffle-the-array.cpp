class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>left;
        vector<int>right;
        vector<int>ans(2*n);
        
        for(int i = 0 ; i< n ; i++)
        {
            left.push_back(nums[i]);
        }
        
        for(int i = n ; i< 2*n ; i++)
        {
            right.push_back(nums[i]);
        }
        int count1=0;
        int count2=0;
        for(int i = 0 ; i<2*n ; i++)
        {
            if(i%2==0)
            {
                ans[i] = left[count1];
                count1++;
            }
            else
            {
                ans[i] = right[count2];
                count2++;
            }
        }
        return ans;
    }
};