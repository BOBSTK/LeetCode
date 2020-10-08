class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()); //排序
        //myNums = nums;
        tar = target;
        numSize = nums.size();
        if(numSize < 4)
          return ans;
        DFS(0,0,nums); 
        return ans;
    }

    //回溯
    void DFS(int low,int sum,vector<int>& nums){
        if(sum == tar && subans.size() == 4){  //找到符合要求的四元组
            ans.push_back(subans);
            return;
        }
        for(int i=low;i<numSize;++i){
            if(numSize - i <  int(4 - subans.size()))//剪枝 剩余可选的数字数量少于 n
               return;
            if(i>low && nums[i] == nums[i-1])  //去重
               continue;
            if(i<numSize -1 && sum + nums[i] + int(3 - subans.size()) * nums[i + 1] > tar ) //剪枝  后面数字加上后一定大于target
               return;
            if (i < numSize - 1 && sum + nums[i] + int(3 - subans.size()) * nums[numSize - 1] < tar) //剪枝  后面数字加上后一定小于target
               continue;
            subans.push_back(nums[i]);
            DFS(i+1,nums[i]+sum,nums); 
            subans.pop_back(); //回溯
        }
        return;
    }

private:
   vector<vector<int>> ans;
   vector<int> subans;  
   int tar, numSize;
};