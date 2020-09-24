#include<iostream>
#include<set>
using namespace std;
int count_1(long long x){ //统计每个数字1的个数
    int ret = 0;
    while(x){
        if(x%2 == 1)
            ++ret;
        x /=2;
    }
    return ret;
}
int main(){
    int T; 
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        set<int> ret;
        while(N--){  
            long long x;
            cin>>x; 
            ret.insert(count_1(x));
        }
        cout<<ret.size()<<endl;
    }
}