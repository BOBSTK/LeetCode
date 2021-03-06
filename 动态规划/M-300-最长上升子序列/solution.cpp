class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
          return 0;
        vector<int> dp(nums.size(),0);
        dp[0] = 1;
        int LIS = 1;  //存储最长子序列长度
        for(int i = 1;i<nums.size();i++){
            dp[i] = 1;
            for(int j = 0;j<i;j++){
                if(nums[i] > nums[j]){ 
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if(LIS < dp[i])
              LIS = dp[i];
        }
        return LIS;
    }
};