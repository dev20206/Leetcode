#include <string>
#include <climits> // For INT_MAX and INT_MIN

class Solution {
public:
    int myAtoi(const std::string& s) {
        int sign = 1, res = 0, idx = 0;
        int n = s.size();

        // Ignore leading whitespaces
        while (idx < n && s[idx] == ' ') {
            idx++;
        }

        // Handle sign
        if (idx < n && (s[idx] == '-' || s[idx] == '+')) {
            if (s[idx] == '-') {
                sign = -1;
            }
            idx++;
        }

        // Construct the number digit by digit
        while (idx < n && s[idx] >= '0' && s[idx] <= '9') {
            // Handle overflow/underflow
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[idx] - '0' > (INT_MAX % 10))) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            // Append current digit to the result
            res = 10 * res + (s[idx++] - '0');
        }

        // Return the result with the sign
        return res * sign;
    }
};
