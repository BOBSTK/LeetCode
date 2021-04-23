class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int f_1,f_2,f_3;  // 使用三个变量代替状态转移数组
        f_1 = 0;
        f_2 = 1;
        for(int i=1;i<=n;++i){
            f_3 = 0;
            if(s[i-1] != '0'){
                f_3 += f_2;
            } 
            if(i > 1 && s[i-2] != '0' &&  ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)){
                f_3 += f_1;
            }
            f_1 = f_2;
            f_2 = f_3;
        }
        return f_3;
    }
};