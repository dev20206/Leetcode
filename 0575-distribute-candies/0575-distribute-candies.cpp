#include <vector>
#include <unordered_set>
#include <algorithm> // Include the <algorithm> header for std::min

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        
        unordered_set<int> candySet;
        
        for(int i = 0; i < n; ++i) {
            candySet.insert(candyType[i]);
        }
        
        // Return the minimum of the number of unique candies and half of total candies
        return static_cast<int>(candySet.size() < n / 2 ? candySet.size() : n / 2);
    }
};
