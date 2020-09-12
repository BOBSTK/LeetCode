class Solution {
public:
    int longestPalindrome(string s) {
       int char_map[128] = {0}; //字符哈希
       int max_length = 0;  //回文串偶数部分最大长度
       int flag = 0;        //是否有中心点
       for(int i =0 ; i<s.length();i++){
           ++char_map[s[i]];
       }
       for(int i=0;i<128;i++){
           //如果字符有偶数个
           if( char_map[i] %2 == 0){
               max_length += char_map[i]; 
           }
           else{ //奇数个字符
                max_length += char_map[i]-1; //加上偶数部分
                flag = 1;  //设置一个中心点
           }
       }
       return max_length + flag;
    }

};