#include <string> // Include the <string> header for using std::string
#include <cmath>  // Include the <cmath> header for using the abs function

class Solution {
public:
    int scoreOfString(std::string s) { // Use std::string instead of string
        int sum = 0;
        for (int i = 0; i < s.length() - 1; i++) { // Loop until i < s.length()
            int c = s[i];
            int c1 = s[i + 1];
            sum += abs(c - c1); // Correct the calculation of the absolute difference
        }
        return sum;
    }
};
