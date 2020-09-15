class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
         return 0;
        vector <int> stack;
        stack.push_back(nums[0]);
        for(int i=1; i< nums.size(); i++){
            if(nums[i] > stack.back()){
                stack.push_back(nums[i]);
            }else{
                for(int j=0;j<stack.size();j++){
                    if(stack[j] >= nums[i]){
                        stack[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return stack.size();
    }
};