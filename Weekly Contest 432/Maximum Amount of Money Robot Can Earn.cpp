#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long safeAdd(long long x, long long y) {
        
        if (x > 0 && y > 0 && x > LLONG_MAX - y) 
        return LLONG_MAX;

        if (x < 0 && y < 0 && x < LLONG_MIN - y) 
        return LLONG_MIN;
        
        return x + y;
    }

    int maximumAmount(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, LLONG_MIN)));
        dp[0][0][0] = grid[0][0];
        dp[0][0][1] = (grid[0][0] < 0) ? 0 : LLONG_MIN;
        dp[0][0][2] = (grid[0][0] < 0) ? 0 : LLONG_MIN;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i > 0) dp[i][j][k] = max(dp[i][j][k], safeAdd(dp[i - 1][j][k], grid[i][j]));
                    if (i > 0 && k > 0 && grid[i][j] < 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
                    if (j > 0) dp[i][j][k] = max(dp[i][j][k], safeAdd(dp[i][j - 1][k], grid[i][j]));
                    if (j > 0 && k > 0 && grid[i][j] < 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
                }
            }
        }

        return (int)max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};
