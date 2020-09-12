class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int res = 0; //记录结果
      int char_map[128] = {0}; //记录字符数量的字符哈希
      string word = ""; //当前满足条件的最长字串
      int begin = 0;
      for(int i=0;i<s.length();i++){
          ++char_map[s[i]];
          if(char_map[s[i]] == 1){ //word 中没出现过该字符
             word += s[i];
             if(res < word.length()){
                 res = word.length(); //更新结果
             }
          }
          else{ //将重复的字符[i]删去
              while(begin<i && char_map[s[i]] >1 ){
                 --char_map[s[begin]];
                 ++begin; 
              }
              word = ""; //更新word
              for(int j= begin;j<=i;j++){
                  word += s[j];
              }
          }
      }
     return res;
    }
};