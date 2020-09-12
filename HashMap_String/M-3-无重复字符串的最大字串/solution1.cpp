class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, i = 0, j = 0; 
        vector<int> idx(128, -1); //记录字符上次出现的位置
        while(j < s.size())
        {
            if(idx[s[j]] >= i) //如果出现重复字符
            {
                res = max(res, j - i); //更新结果
                i = idx[s[j]] + 1;     //移动指针
            } 
            idx[s[j++]] = j;     //更新idx
        }
        res = max(res, j - i); //更新结果(最后)
        return res;
    }
};

