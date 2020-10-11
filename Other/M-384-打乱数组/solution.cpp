class Solution {
public:
//洗牌算法
//确保有n!种可能
    Solution(vector<int>& nums) {
      this->nums = nums;
      this->original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
       nums.clear();
       nums = original;
       return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            int rd = rand()%(n-i);
            swap(nums[i],nums[i+rd]);
        }
        return nums;
    }

private:
   vector<int> nums;  
   vector<int> original;   
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */