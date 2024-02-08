#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findmax(vector<int>& v) {
        int maxi = INT_MIN;
        for(int i = 0; i < v.size(); i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }
    
    int64_t calculatetotalhours(vector<int>& v, int hourly) {
        int64_t totalh = 0;
        int n = v.size();
        for(int i = 0; i < n; i++) {
            totalh += ceil(static_cast<double>(v[i]) / hourly);
        }
        return totalh;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmax(piles);
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int64_t totalh = calculatetotalhours(piles, mid);
            if(totalh <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
