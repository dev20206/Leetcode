#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveex = 0;
        int tenex = 0;

        for (int bill : bills) {
            if (bill == 5) {
                fiveex++;
            } else if (bill == 10) {
                if (fiveex == 0) {
                    return false;
                }
                fiveex--;
                tenex++;
            } else { // For bill of 20
                if (tenex > 0 && fiveex > 0) {
                    tenex--;
                    fiveex--;
                } else if (fiveex >= 3) {
                    fiveex -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
