class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int length = nums.size();
        int left = 0;
        int right = length;
        while(left<right){
            if(nums[left] == val){
                nums[left] = nums[right-1];
                --right;//这里left不右移，因为right指向的值也可能是val
            }else{
                ++left;
            }
        }
        return left;
    }
    
};