class Solution {
    //以k/i的概率选第i个数
public:
    Solution(vector<int>& nums) {
      this->nums = nums;
    }
    
    int pick(int target) {
      int count = 0; //记录这已经是第几次出现了
      int index;
      for(int i=0;i<nums.size();i++){
          if(nums[i] == target){ //找到target
               ++count;
               //以1/count的概率决定要不要取这个数
               if(rand()%count==0){
                   index = i;
               }
          }
      }
      return index;
    }
private:
   vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */