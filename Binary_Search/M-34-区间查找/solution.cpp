class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> result;
          
        //找到左端点
        result.push_back(left_bound(nums,target));
        result.push_back(right_bound(nums,target));
        return result;
    }

    //找到左端点
    int left_bound(std::vector<int>& nums,int target){
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(target == nums[mid]){
               if(mid == 0 ||target > nums[mid-1]){
                   return mid;
               }
               right = mid -1;
            }
            else if(target < nums[mid]){
                right = mid -1;
            }
              else if(target > nums[mid]){
                 left = mid +1;
            }
        }
        return -1;
    }

    //找到右端点
    int right_bound(std::vector<int>& nums,int target){
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(target == nums[mid]){
               if(mid == nums.size()-1 ||target < nums[mid+1]){
                   return mid;
               }
               left = mid + 1;
            }
            else if(target < nums[mid]){
                right = mid -1;
            }
              else if(target > nums[mid]){
                 left = mid +1;
            }
        }
        return -1;
    }
};