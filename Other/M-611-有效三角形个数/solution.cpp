class Solution {
public:
    int triangleNumber(vector<int>& nums) {
      int n = nums.size();
      if(n<3)
       return 0;
      //排序
      sort(nums.begin(),nums.end());
      int ret =0;
      for(int i =n-1;i>=2;i--){  //固定一个大数
          int j = 0; //指向最小的数
          int k = i-1; 
          while(j<k){
              if(nums[j]+nums[k]>nums[i]){ //符合要求
                  ret += k-j;//中间的数都满足
                  --k;
              }else{
                  ++j;
              }
          }
          
      }
      return ret;
    }
};