class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(target == nums[mid]){
                return mid;
            }
            else if(target < nums[mid]){ 
                if(nums[mid]>nums[left]){ //左边是正常递增序列
                    if(target < nums[left]){
                        left = mid+1;
                    }else{
                        right = mid-1;
                    }
                }else if(nums[mid] < nums[left]){ //右边是递增序列
                      right = mid-1;
                }
                else if(nums[mid] == nums[left]){ //只有两个元素的情况
                 left = mid+1;
                }
            }
            else if(target > nums[mid]){
                if(nums[mid]>nums[left]){ //左边是正常递增序列
                  left = mid+1;
                }else if(nums[mid] < nums[left]){ //右边是递增序列
                  if(target >= nums[left]){
                      right = mid-1;
                  }else{
                      left = mid+1;
                  }
                }
                else if(nums[mid] == nums[left]){ //只有两个元素的情况
                 left = mid+1;
                }
            }
        }
        return -1;
    }
};