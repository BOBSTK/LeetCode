// @lc code=start
class Solution {
public:
    bool isDigit(char c){
        return c>='0' && c<='9';
    }
    int myAtoi(string s) {
        int sign = 1;
        int n = s.size();
        int ret = 0;
        int i;
        // 过滤掉前导空格
        for(i=0;i<n;++i){
            char c = s[i];
            if(' '==c){
                continue;
            }else{
                if(c == '-'){
                    sign = -1;
                    ++i;
                    break;
                }else if(c == '+'){
                    sign = 1;
                    ++i;
                    break;
                }
                else if(isDigit(c)){
                    cout<<"读取数字"<<endl;
                    break; // 读取数字
                }else{
                    return ret;
                }
            }
        }

        for(i;i<n;++i){
            char c = s[i];
            if(isDigit(c)){
                //判断溢出问题
                int temp = c-'0';
                if(sign == 1 && ret > (INT_MAX-temp)/10){
                    return INT_MAX;
                }else if(sign == -1 && (-ret<INT_MIN/10 || (-ret == INT_MIN/10 && temp >=8) ) ){
                    return INT_MIN;
                }
                ret = ret*10 + temp;
            }else{
                return sign * ret;
            }
        }
        return sign * ret;
    }
};