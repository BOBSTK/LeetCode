#include <iostream>
using namespace std;

#include<vector>
/**
 * 给定n，找 [1,n]之间的素数个数
 * **/
namespace Sieve_of_Eratosthenes{
   int CountPrimes(int n){
       vector<int> isPrim(n+1,1);
       for(int i=2;i*i<=n;++i){
           if(isPrim[i] == 1){
              for(int j=i*i;j<=n;j+=i){
                  isPrim[j] = 0;
              }
           }
       } 
       int count = 0;
       for(int i=1;i<=n;++i){
           cout<<isPrim[i]<<endl;
           if(isPrim[i] == 1){
               ++count;
           }
       }
       return count;
   }
}
int main(){
    cout<<Sieve_of_Eratosthenes::CountPrimes(7)<<endl;
}