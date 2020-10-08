class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        map<int,int> hash;
        for(int i = 0;i<nums.size();i++){
            if(hash.find(target-nums[i]) != hash.end()){ //在放入nums[i]之前查询
                ret.push_back(hash[target-nums[i]]);
                ret.push_back(i);
                return ret;
            }
            hash[nums[i]] = i;
        }
        return ret; 
    }
};