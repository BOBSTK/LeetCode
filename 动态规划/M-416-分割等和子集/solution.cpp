class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        if(size<2)
          return false;
        int total = 0;
        //排序
        sort(nums.begin(),nums.end());
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
        vector<vector<int>> dp(size,vector<int>(target+1,0)); //初始化dp数组,初始时全为0  {dp}[i][j] 表示从数组的 [0,i] 下标范围内选取若干个正整数（可以是 0 个），是否存在一种选取方案使得被选取的正整数的和等于 j
        //边界问题
        dp[0][nums[0]] = 1; //i=0时，只有一个数nums[0]可以达到
        for(int i=0;i<size;i++)  //j为0时
         dp[i][0] = 1;
        for(int i=1;i<size;i++){
            for(int j=1;j<=target;j++){
                if(j>=nums[i]){ //目标值比当前区间最大值要大  可以选也可以不选
                   //如果不选nums[i],则看dp[i-1][j]是否为1
                   //如果选nums[i]，则看dp[i-1][j-nums[i]]是否满足
                   dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]; 
                }else{ //目标值比当前区间最大值小，不可以选nums[i]
                   dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[size-1][target];
    }

   
};