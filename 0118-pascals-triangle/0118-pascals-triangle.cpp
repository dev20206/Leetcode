#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            long long curr = 1;
            vector<int> ansRow;
            ansRow.push_back(1);
            for (int col = 1; col <= i; col++) {
                curr = curr * (i - col + 1) / col;
                ansRow.push_back(static_cast<int>(curr));
            }
            ans.push_back(ansRow);
        }
        return ans;
    }
};
