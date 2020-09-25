#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//从N个数中取两个数
long long CN2(long long n){ 
    return (n-1)*n/2;
}
int main(){
    long long N,D; //N - 建筑数量  D - 最大距离
    cin>>N>>D;
    if(N<3){  //建筑数量小于3，直接返回
        cout<<0<<endl;
        return 0;
    }
    vector<long long> buildings(N,0);
    int begin = 0;
    long long count = 0; //记录结果
    for(int end = 0; end < N;end++){
        cin>>buildings[end]; 
        //end>2 至少要三个建筑来放三个人    //begin 在 和 end重合时距离为0退出循环
        while(end >= 2 && buildings[end] - buildings[begin] > D){ 
            ++begin;  
        }
       count += CN2(end-begin); //当begin 与 end 距离小于2时结果为0
    }
    cout<<count%99997867<<endl;
}