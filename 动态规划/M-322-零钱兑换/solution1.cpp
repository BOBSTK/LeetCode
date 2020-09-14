void coinChange(vector<int>& coins, int amount, int c_index, int count, int& ans)
{
    if (amount == 0) //金额为0说明找到了一种解法
    {
        ans = min(ans, count);  //如果比现在的结果好，更新
        return;
    }
    if (c_index == coins.size()) return; //所有硬币都试过后解决，返回

    for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--) //尝试所有硬币的可能（如果加上k后大于当前最小解，那么这个面额和比它小的硬币都不在考虑）
    {
        coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
    }
}

int coinChange(vector<int>& coins, int amount)
{
    if (amount == 0) return 0;
    sort(coins.rbegin(), coins.rend()); //将硬币从小到大排序
    int ans = INT_MAX; 
    coinChange(coins, amount, 0, 0, ans); //从最大的硬币开始
    return ans == INT_MAX ? -1 : ans;
}
