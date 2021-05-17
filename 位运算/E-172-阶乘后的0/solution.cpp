/**
 * 10 = 2 x 5
 * 1 ,..., n中有多少个因子5
 * 
 * **/
class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0) return 0; // 0! = 1
        long divisor = 5;
        int ret = 0;
        while(divisor<=n){
            //cout<<"divisor "<<divisor<<endl;
            int count = n/divisor;
            //cout<<"count "<<count<<endl;
            divisor *= 5;
            ret += count;
        }
        return ret;
    }
};