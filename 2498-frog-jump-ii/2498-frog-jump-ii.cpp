class Solution {
 public:
  int maxJump(vector<int>& stones) {
     
    // F1 and F2 increase, resulting a larger `ans`.
    int ans = stones[1] - stones[0];  // If there're only two stones.
    for (int i = 2; i < stones.size(); ++i)
      ans = max(ans, stones[i] - stones[i - 2]);
    return ans;
  }
};