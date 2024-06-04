#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    int longestPalindrome(std::string s) {
        std::unordered_map<char, int> s1;
        std::vector<int> odd;
        int even = 0;

        // Count the frequency of each character
        for (char c : s) {
            s1[c]++;
        }

        // Separate counts into odd and even
        for (auto it : s1) {
            if (it.second % 2 != 0) {
                odd.push_back(it.second);
            } else {
                even += it.second;
            }
        }

        // If there are no odd counts, return the sum of even counts
        if (odd.empty()) {
            return even;
        }

        // Sort odd counts in descending order
        std::sort(odd.begin(), odd.end(), std::greater<int>());

        // Add the largest odd count to the even counts
        int sum = odd[0] + even;

        // Add the remaining odd counts (decremented by 1 to make them even)
        for (int i = 1; i < odd.size(); ++i) {
            sum += odd[i] - 1;
        }

        return sum;
    }
};
