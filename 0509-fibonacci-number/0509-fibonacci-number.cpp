class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;

        int prev2 = 0;
        int prev1 = 1;
        int cur;
        for(int i = 2; i <= n; i++) { // Start from i = 2, as we already have values for n = 0 and n = 1
            cur = prev1 + prev2;
            prev2 = prev1; // Update prev2 with the value of prev1
            prev1 = cur;   // Update prev1 with the current value
        }
        return cur;
    }
};
