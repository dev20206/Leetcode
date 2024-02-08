#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool possiblea(vector<int>& bloomDays, long long days, int m, int k) {
        long long cnt = 0;
        long long noofb = 0;
        for (int i = 0; i < bloomDays.size(); i++) {
            if (bloomDays[i] <= days)
                cnt++;
            else {
                noofb += cnt / k;
                cnt = 0;
            }
        }
        noofb += cnt / k; // Handle remaining flowers after loop ends
        return noofb >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (auto i : bloomDay) {
            maxi = max(maxi, i);
            mini = min(mini, i);
        }
        long long low = mini;
        long long high = maxi;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (possiblea(bloomDay, mid, m, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)low;
    }
};
