class Solution {
public:
    static bool customComparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; // Sort based on the second element of each pair
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), customComparator); // Sort by second element
        int count = 1; // At least one pair is always part of the chain
        int currentEnd = pairs[0][1]; // Track the end of the first pair in the sorted list

        for (int i = 1; i < pairs.size(); ++i) {
            // Compare the second element of the current pair with the first element of the next
            if (pairs[i][0] > currentEnd) {
                count++; // Increment count if they can form a valid chain
                currentEnd = pairs[i][1]; // Update the end of the current chain
            }
        }

        return count;
    }
};
