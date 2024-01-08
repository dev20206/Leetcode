class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int k=n;
        int j=0;
        vector<int> temp(n);
        for(int i=0; i<n;i++)
        {
            if(nums[i]==0)
            {
                temp[(k-1)%nums.size()]==0;
                k--;
            }
        }
        for(int i=0; i<n;i++)
        {
            if(nums[i]!=0)
            {
                temp[j]=nums[i];
                j++;
            }
        }
        nums=temp;
    }
};