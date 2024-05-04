class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)
            return 1;
        int left = 0;
        int right = 1;
        int sum = 0;
        for(int i = 0 ; i<n ; i++)
        {
            sum = left+right;
            left = right;
            right = sum;
            
        }
        return sum;
    }
};