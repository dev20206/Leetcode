class Solution {
public:

    int findTheWinner(int N, int k) {
        int i = 1, ans = 0;

        // Run a while loop till i <= N

        while (i <= N) {

        // Update the Value of ans and Increment i by 1
        ans = (ans + k) % i;
        i++;
        }

    // Return required answer
    return ans + 1;
    }
};