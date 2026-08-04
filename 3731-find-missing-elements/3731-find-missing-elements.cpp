class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;

        sort(nums.begin(), nums.end());

        int small = nums[0];
        int large = nums[nums.size() - 1];

        while (small <= large) {
            int flag = 0;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == small) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                ans.push_back(small);
            }

            small++;
        }

        return ans;
    }
};