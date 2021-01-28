class Solution {
public:
    /**
    记数组的全部元素之和为 total，当遍历到第 i 个元素时，设其左侧元素之和为 sum，则其右侧元素之和为
total - nums[i] - sum。左右侧元素相等即为 2 sum + nums[i] = total
    **/
    int pivotIndex(vector<int>& nums) {
        // 计算total
        if(nums.size() <=1)
          return -1;
        int total = 0;
        vector<int> sum(nums.size(),0);
        for(int i=0;i<nums.size();++i){
            sum[i] = total;
            total += nums[i];
        }
        for(int i =0 ;i<sum.size();++i){
            if(sum[i]*2+nums[i] == total)
              return i;
        }
        return -1;
    }
};