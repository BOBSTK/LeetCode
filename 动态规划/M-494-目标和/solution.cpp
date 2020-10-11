class Solution {
public:
   int cnt = 0;
   int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0)
         return 0;
         dfs(nums, S, 0);
         return cnt;
    }

    void dfs(vector<int> &nums, uint target, int idx) {
       if(idx >= nums.size()){
           if(target == 0)
             ++cnt;
           return;
       }
    
       dfs(nums, target - nums[idx], idx + 1);
       dfs(nums, target + nums[idx], idx + 1);
       return ;
    }


};