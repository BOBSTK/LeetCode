/**
 * 前缀和
 * **/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        hash[0] = 1;
        int pre = 0;  // 记录前缀和 
        int count = 0; 
        for(int x : nums){
            pre += x;
            if(hash.find(pre - k) != hash.end()){ 
                count += hash[pre-k]; // 找到 1...i中是否又满足要求的前缀和
            }
            ++hash[pre]; // 记录pre出现的次数
        }
        return count;
    }
private:
    unordered_map<int,int> hash; // 记录 pre[j]对应的值出现了几次
};