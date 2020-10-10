class Solution {
public:
    int base = 1337;
    int superPow(int a, vector<int>& b) {
      if(b.empty())
        return 1;
      //取出最后一个数
      int last = b.back();
      b.pop_back();

      int part1 = myPow(a,last);
      int part2 = myPow(superPow(a,b),10);
      //合并结果
      return (part1 * part2) % base;
    }
    
    //计算 a^k
    int myPow(int a,int k){
       if(k==0)
         return 1;
       //对因子求模
       a %= base;
       if(k%2==1){//奇数
         return (a*myPow(a,k-1))%base;
       }else{ //偶数
         int sub = myPow(a,k/2);
         return (sub * sub) % base;
       }
       
    }
};