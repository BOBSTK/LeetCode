class Solution {
public:
   //把 nums 划分成两个子集 A 和 B，分别代表分配 + 的数和分配 - 的数
   //sum(A) - sum(B) = target
   //sum(A) = target + sum(B)
   //sum(A) + sum(A) = target + sum(B) + sum(A)
   //2 * sum(A) = target + sum(nums)
   //求一个子集A


   int findTargetSumWays(vector<int>& nums, int S) {
      if(nums.size()<=0)
       return 0;
      //计算sum(nums)
      long sum =0;
      for(int i:nums)
        sum += i;
      if((S+sum)%2==1 || sum<S) //不可能有解
        return 0;  
      S = (S+sum)/2;
      vector<int> dp(S+1,0); //dp[j] 在(0,i)中选物品，能够使背包装满的解法
      dp[0] = 1; //不放元素就可以达到0
      for(int i=0;i<nums.size();i++){
          for(int j=S;j>=nums[i];j--){
              dp[j] += dp[j-nums[i]];
          }
      }
      return dp[S];
    }
};