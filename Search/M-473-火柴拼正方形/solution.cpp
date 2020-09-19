class Solution {
public:
    bool makesquare(vector<int>& nums) {
       if(nums.size() < 4)
         return false;
       int sum = 0;
       for(int i=0;i<nums.size();i++){
           sum += nums[i];
       }
       if(sum % 4 != 0)
         return false;
       int length = sum/4; //边长

       sort(nums.rbegin(),nums.rend()); //从大到小排序
       int bucket[4] = {0};
       return BackTracking(0,nums,length,bucket);
    }
private:
    
    bool BackTracking(int i,vector<int>& nums,int length,int bucket[]){
       if(i >= nums.size()){
           return bucket[0] == length && bucket[1] == length && bucket[2] == length && bucket[3] == length;
       }
       for(int j=0;j<4;j++){
           if(bucket[j] + nums[i] > length) //不能在这条边放火柴
             continue;
           //在这条边放火柴
           bucket[j] += nums[i];
           if(BackTracking(i+1,nums,length,bucket)){//考虑下一根火柴
               return true;
           } 
           bucket[j] -= nums[i]; //撤销选择
       }
       return false;
    }
};