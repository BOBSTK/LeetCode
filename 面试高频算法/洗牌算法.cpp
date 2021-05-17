#include <iostream>
using namespace std;

#include<time.h>
#include<vector>
namespace Knuth_Durstenfeld_Shuffle{
    /**
     * 算法描述
     * 给定n
     * 返回[1,2,3,...,n]随机排列的数组
     * **/
    void swap(vector<int>& v,int i,int j){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

    vector<int> RandVector(int n){
        srand((unsigned)time(nullptr)); 
        vector<int> ret;
        for(int i=1;i<=n;++i){
            ret.push_back(i);
        }
        /**
         * 一个元素m被放置在第i个位置的概率 = 前i-1个位置选择元素时没有选中的概率 * 第i个位置选中m的概率
         * 
         * **/
        for(int i=0;i<n-1;++i){
            int j = rand()%(n-i);
            swap(ret,i,j);
        }
        return ret;
    }
}
int main(){
    vector<int> random_vector = Knuth_Durstenfeld_Shuffle::RandVector(5);
    for(int i=0;i<random_vector.size();++i){
        cout<<random_vector[i]<<endl;
    }

}