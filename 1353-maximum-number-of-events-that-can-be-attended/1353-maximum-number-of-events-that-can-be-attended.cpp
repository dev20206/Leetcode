#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });

        int j = 0;
        int attended = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 1; i < 100001; i++) {
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }

            for (; j < events.size() && events[j][0] == i; j++) {
                pq.push(events[j][1]);
            }

            if (!pq.empty()) {
                pq.pop();
                attended++;
            }
        }

        return attended;
    }
};
