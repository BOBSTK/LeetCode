/**
 * 完全背包问题
 * dp[i][j] 用前i种硬币，凑到j的组合数
 * dp[i][j] = dp[i-1][j] + dp[i][j-w[i]]
 * 
 * **/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1,0);
        dp[0] = 1;
        for(int i=0;i<n;++i){
            for(int j=coins[i];j<=amount;++j){
                dp[j] = dp[j] + dp[j-coins[i]]; 
            }
        }
        return dp[amount];
    }
};