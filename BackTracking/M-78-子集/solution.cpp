class Solution {
public:
    void generate(int i, vector<int>&nums,vector<int>&item,vector<vector<int>>&result){
      if(i>=nums.size())
      return;
      //放num[i]的情况
      item.push_back(nums[i]);
      result.push_back(item); //将当前结果子集加入result
      generate(i+1,nums,item,result);
      //不放num[i]的情况
      item.pop_back();
      generate(i+1,nums,item,result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; //存储最终结果
        vector<int> item; //回溯时，产生各个子集的数组
        result.push_back(item); //将空集导入result
        generate(0,nums,item,result); //计算各个子集
        return result;
    }
};