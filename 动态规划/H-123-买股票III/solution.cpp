// @lc code=start
class Solution {
public:
    /**
     * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
     * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
     * **/
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_i_1_0 = 0,dp_i_1_1 = INT_MIN;
        int dp_i_2_0 = 0,dp_i_2_1 = INT_MIN;
        for(int i=0;i<n;++i){
            dp_i_2_0 = max(dp_i_2_0, dp_i_2_1 + prices[i]);
            dp_i_2_1 = max(dp_i_2_1, dp_i_1_0 - prices[i]);
            dp_i_1_0 = max(dp_i_1_0, dp_i_1_1 + prices[i]);
            dp_i_1_1 = max(dp_i_1_1, -prices[i]);
        }
        return dp_i_2_0;
    }
};