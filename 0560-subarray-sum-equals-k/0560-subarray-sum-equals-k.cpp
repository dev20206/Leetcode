#include <vector>
#include <map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::map<int, int> mpp;
        mpp[0] = 1;
        int presum = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            int complement = presum - k;
            cnt += mpp[complement];
            mpp[presum]++;
        }
        return cnt;
    }
};
