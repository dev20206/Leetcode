class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int low = 0;  
        int high = nums.size()-1;
        int count = 0;
        int mid = (low+high)/2;
        while(low<=high)
        {
            if(low==high)
            {
                break;
            }
            if(low!=high)
            {
                count+=nums[mid]-nums[low];
                count+=nums[high]-nums[mid];
                low++;
                high--;
            }

        }
        return count;
        
    }
};