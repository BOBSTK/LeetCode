class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      if(coins.size() == 0)
        return 0;
      //初始化dp数组
      vector<int> dp;
      for(int i=0;i<=amount;i++){
         dp.push_back(-1); //dp[i] 达到金额i所需的最少硬币数量
      }
      dp[0] = 0;
      
      for(int i=1;i<=amount;i++){  //遍历所有金额
          for(int j=0;j<coins.size();j++){  //遍历所有硬币 
              if(i-coins[j] >= 0 && dp[i-coins[j]]!=-1){   
                  if(dp[i] == -1 || dp[i] > dp[i-coins[j]] + 1){ //如果dp[i]第一次考虑或者出现更小的结果，更新
                      dp[i] =  dp[i-coins[j]] + 1;
                  }
              }
          }
      }
      return dp[amount];
    }
};