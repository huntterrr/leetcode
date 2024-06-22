#include <vector>
using namespace std;

vector<int> dp;
class Solution {
public:
    bool f(int total, int state, int maxInt) {
        if (dp[state] != -1) return dp[state];
        if (total <= 0) return false;

        for (int i = 1; i <= maxInt; i++) {
            int mask = (1 << i);
            if (!(state & mask)) {
                int newState = state | mask;
                if (!f(total - i, newState, maxInt)) {
                    dp[state] = true;
                    return true;
                }
            }
        }
        dp[state] = false;
        return false;
    }

    bool canIWin(int maxInt, int desiredTotal) {
        int maxSum = (maxInt * (maxInt + 1)) / 2;
        if (maxSum < desiredTotal) return false;
        if (desiredTotal == 0) return true;

        dp.assign((1 << 21), -1);
        return f(desiredTotal, 0, maxInt);
    }
};
