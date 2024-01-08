class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int max=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                count++;
            }
            else
            {
                count=0;
            }
            
            if(count>=max)
                {
                    max=count;
                }
        }
        return max;
    }
};