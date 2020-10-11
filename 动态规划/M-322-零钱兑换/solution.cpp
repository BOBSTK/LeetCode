class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       if(coins.size() == 0)
         return 0;
       vector<int> dp(amount+1,amount+1);  //dp[i]代表达到金额i时最少使用的硬币个数
       dp[0] = 0; //初始值
       for(int i=1;i<=amount;i++){
           for(int j =0;j<coins.size();j++){
               if(i-coins[j]>=0 && dp[i-coins[j]]!=amount+1){   
                   dp[i] = min(dp[i-coins[j]]+1,dp[i]);
               }
           }
       }
       
       return dp[amount]==amount+1?-1:dp[amount];
    }
};