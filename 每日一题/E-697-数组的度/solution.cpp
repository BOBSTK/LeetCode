class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
      unordered_map<int,vector<int>> hash;
      int n = nums.size();
      for (int i = 0; i < n; i++) {
            if (hash.count(nums[i])) { // 如果nums[i]已经出现过了
                hash[nums[i]][0]++;   // 统计出现次数
                hash[nums[i]][2] = i; // 统计最后出现的位置
            } else { 
                hash[nums[i]] = {1, i, i}; // 记录信息
            }
       }
       int maxNum = 0, minLen = 0;
       for (auto& [_, vec] : hash){  //遍历hash表
          if(vec[0]>maxNum){  //出现了新的最大度
            maxNum = vec[0];
            minLen = vec[2]-vec[1]+1; //更新最短连续子数组长度
          }else if(maxNum == vec[0]){
              minLen = min(minLen,vec[2]-vec[1]+1);
          }
       }
       return minLen;
    }
      
};