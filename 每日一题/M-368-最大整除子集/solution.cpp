// 如果 c 是 s1 最小整数的约数，可以将 c 添加
// 如果 c 是 s1 最大整数的倍数，可以将 c 添加

// 状态定义 dp[i] 表示在输入数组 nums 升序排列的前提下，以 nums[i] 为最大整数的「整除子集」的大小
// 状态转移方程：枚举 j=0…i−1 的所有整数 nums[j]，如果 nums[j] 能整除 nums[i]，说明 nums[i] 可以扩充在以 nums[j] 为最大整数的整除子集里成为一个更大的整除子集。
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        sort(nums.begin(),nums.end()); //排序
        int maxSize = 1;
        int maxVal = dp[0];
        // 求以nums[i] 为最大整数的整除子集
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j] == 0){
                    dp[i] = max(dp[i],dp[j]+1);
                }
                if(dp[i]>maxSize){
                    maxSize = dp[i];
                    maxVal = nums[i];
                }
            }
        }
        cout<<maxSize<<" "<<maxVal<<endl;
        // 如果都是互质的数，输出第一个数
        vector<int> ans;
        if (maxSize == 1) {
            ans.push_back(nums[0]);
            return ans;
        }
        // 倒推获得最大子集
        for(int i=n-1;i>=0 && maxSize>0;--i){
            if(maxVal%nums[i]==0 && dp[i] == maxSize){
                ans.push_back(nums[i]);
                maxVal = nums[i];
                --maxSize;
            }
        }

        return ans;
    }
};