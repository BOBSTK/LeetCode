// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /**
         * 
         *   dp[i][k][0/1] i -- 天数  k -- 允许交易的最大次数 0/1 -- 持有/未持有
         *   状态转移方程
         *   dp[i][k][0] = max( dp[i-1][k][0] , dp[i-1][k-1][1] + prices[i])
         *                       选择rest          选择sell
         *   
         *   dp[i][k][1] = max( dp[i-1][k][1] , dp[i-1][k-1][0] - prices[i])
         *                       选择rest          选择buy
         *   
         *   初始状态
         *   dp[-1][k][0] = 0
         *   dp[-1][k][1] = -inf
         *   dp[i][0][0]  = 0   
         *   dp[i][0][1] = -inf  
         * **/  
        int n = prices.size();
        if(n<=1) return 0;
        vector<vector<int> >dp = vector<vector<int> >(n,vector<int>(2));
        for(int i=0;i<n;++i){
            if(i==0){ // 初始值
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1],  - prices[i]);
        }  
        return dp[n-1][0];          
        
    }
};