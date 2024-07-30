class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> ans;
        
        // Filter out the positive numbers
        for (int num : nums) {
            if (num > 0) {
                ans.push_back(num);
            }
        }
        
        // If there are no positive numbers, return 1
        if (ans.empty()) {
            return 1;
        }

        // Sort the positive numbers
        sort(ans.begin(), ans.end());

        // Find the first missing positive number
        int smallestPositive = 1;
        for (int num : ans) {
            if (num == smallestPositive) {
                smallestPositive++;
            } else if (num > smallestPositive) {
                break;
            }
        }
        
        return smallestPositive;
    }
};
