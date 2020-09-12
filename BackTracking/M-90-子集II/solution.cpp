class Solution {
public:
    void generate(int i, vector<int>&nums,vector<int>&item,vector<vector<int>>&result,set<vector<int>> &res_set){
      if(i>=nums.size())
       return;
      //放num[i]的情况
      item.push_back(nums[i]);
      if(res_set.find(item) == res_set.end()){ //如果set中不存在item
         result.push_back(item); //将当前结果子集加入result
         res_set.insert(item);
      }    
      generate(i+1,nums,item,result,res_set);
      //不放num[i]的情况
      item.pop_back();
      generate(i+1,nums,item,result,res_set);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result; //存储最终结果
        vector<int> item; //回溯时，产生各个子集的数组
        set<vector<int>> res_set; //去重使用的集合
        sort(nums.begin(),nums.end()); //对nums数组排序
        result.push_back(item); //将空集导入result
        generate(0,nums,item,result,res_set); //计算各个子集
        return result;
    }
};