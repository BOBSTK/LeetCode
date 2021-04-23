# define MAX_NUM  1005
int shift[MAX_NUM];
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m == 0) return 0;
        // 预处理
        for(int i=0;i<MAX_NUM;++i){
            shift[i] = m+1; //主串移动的数量
        }
        for(int i=0;i<m;++i){  //记录每个模式串中出现的字符需要移动的距离
            shift[needle[i]] = m - i;
        }
        int i = 0;int j =0;  // 主串和模式串下标
        while(i<=n-m){
            j = 0;
            while(haystack[i+j] == needle[j]){
                ++j;
                if(j>=m)
                   return i; //匹配成功
            }
            // 移动
            i += shift[haystack[i+m]];
        }
        return -1;

    }
};