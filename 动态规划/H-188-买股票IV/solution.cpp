/**
 * 最多交易次数应该小于n/2
 * dp[i][k][0] = max( dp[i-1][k][0], dp[i-1][k][1] + prices[i])
 * dp[i][k][1] = max ( dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
 * **/
class Solution {
public:
    // 可以无限次交易
    int maxProfit_k_inf(vector<int>& prices){
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for(int i=1;i<n;++i){
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n<=0){
            return 0;
        }
        if(k>n/2){
            maxProfit_k_inf(prices); // k<n/2，可以认为k是无限制的
        }
        // int[][] dp = new int[k+1][2];
        vector<vector<int> > dp = vector<vector<int> >(k+1,vector<int>(2));
        for (int i = 1; i <= k; i++) {
            dp[i][0] = 0;
            dp[i][1] = -prices[0];
        }
        for(int i=1;i<n;++i){
            for(int _k = k;_k>=1;--_k){
                dp[_k][0] = max( dp[_k][0], dp[_k][1]+prices[i]);
                dp[_k][1] = max( dp[_k][1], dp[_k-1][0] - prices[i]);
            }  
        }
        return dp[k][0];
    }
};