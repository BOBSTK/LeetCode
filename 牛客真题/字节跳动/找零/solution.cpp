#include<iostream>
#include<vector>
using namespace std;

int coinChange(vector<int> &coins,int amount){
    if(amount == 0) //不需要找硬币
        return 0;
    vector<int> dp (amount+1,-1);
    dp[0] = 0;
    for(int i=1;i<=amount;i++){ //遍历所有金额
        for(int j=0;j<coins.size();j++){//遍历所有硬币 
            if(i-coins[j] >= 0 && dp[i-coins[j]]!= -1){
                if(dp[i] == -1 || dp[i] > dp[i-coins[j]] + 1){ //如果dp[i]第一次考虑或者出现更小的结果，更新
                      dp[i] =  dp[i-coins[j]] + 1;
                  }
            }
        }
    }
    return dp[amount];
}
int main(){
    int N;
    cin>>N;
    int amount = 1024 - N;
    vector<int> coins; //记录有哪些硬币
    coins.push_back(1);
    coins.push_back(4);
    coins.push_back(16);
    coins.push_back(64);
    cout<<coinChange(coins,amount);
}