class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        if(size<2)
          return false;
        int total = 0;
        //排序
        //sort(nums.begin(),nums.end());
        //计算总数
        for(int i=0;i<nums.size();i++){
            total += nums[i];
        }
        if(total%2!=0)  //只有偶数才可能分割成两个相等的子集
          return false;
        int target = total/2;
        if(nums[size-1] > target) //最大数超过总数的一半
            return false;
        
        //动态规划 
        vector<int> dp(target+1,0);//dp[i]代表 i是否可以达到
        dp[0] = 1; //初始值 0肯定可以达到（不选）
        for(int i=0;i<size;i++){ //从第一个数开始
            for(int j = target; nums[i]<=j;--j){   //从后往前，一旦nums[i] > j 则不用继续考虑了
               if(dp[target])
                 return true;
               dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[target];

    }
};