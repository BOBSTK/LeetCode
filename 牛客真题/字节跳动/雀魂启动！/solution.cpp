#include<iostream>
#include<vector>
using namespace std;

bool hasTriples(int n,vector<int> &card){
      if(n==0){
            return true;
        }
        // 1到9，每一张牌尝试三张或顺子
        for (int i = 1; i <= 9; i++) {
            if(card[i]>=3){
                card[i]-=3;
                bool subHashTriples = hasTriples(n-1,card);//判断剩下的牌是否能够凑成足够的顺子或刻子
                card[i]+=3;
                if(subHashTriples){
                    return true;
                }
            }
            //顺子
            if(i<=7  && card[i]> 0 && card[i+1] > 0 && card[i+2]>0){
                --card[i];
                --card[i+1];
                --card[i+2];
                bool subHasTriples = hasTriples(n-1,card); //判断剩下的牌是否能够凑成足够的顺子或刻子
                //回溯
                ++card[i];
                ++card[i+1];
                ++card[i+2];
                if(subHasTriples){
                    return true;
                }
            }
        }
        return false;
}

bool isWin(vector<int>&card){
        // 从1到9 中选择一个作为雀头, 然后判断剩余的牌是否构成4对
        for (int i = 1; i <= 9; i++) {
            if(card[i]<2){
                continue;
            }
            card[i]-=2;
            if(hasTriples(4,card)){
                card[i]+=2;
                return true;
            }
            card[i]+=2;
        }
        return false;
    }

int main(){
    vector<int> card(10,0);
    for(int i=0;i<13;i++){
        int num;
        cin>>num;
        ++card[num];
    }
    int count = 0;
    // 选择1到9中的一个作为第14张牌，然后判断是否胡牌
    for(int i=1;i<=9;i++){
        if(card[i]>=4)
            continue;
        ++card[i];
        if(isWin(card)){
            ++count;
            cout<<i<<" ";
        }
        --card[i];
    }
   
    if(count == 0)
        cout<<count;   
}


