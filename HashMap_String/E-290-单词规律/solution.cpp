class Solution {
public:
    bool wordPattern(string pattern, string s) {
       
       std::map<string,char> word_map; //单词到pattern的映射
       char used[128] = {0};
       string word; //保存拆分出的单词
       int pos = 0;
       s.push_back(' '); //尾部加上一个空格，方便拆分
       for(int i=0;i<s.length();i++){
           if(s[i] == ' '){ //遇到空格，拆分出新单词
              if(pos == pattern.length()){ //超出长度，不匹配
                  return false;
              }
              if(word_map.find(word) == word_map.end()){ //单词未出现在map中
                 if(used[pattern[pos]] == 1) //如果对应的pattern已经使用过
                  return false;
                 word_map[word] = pattern[pos]; //添加新的映射
                 used[pattern[pos]] = 1;
              }
              else{ //单词出现在map中
                 if(pattern[pos] != word_map[word]){ //不匹配
                     return false;
                 }
              }
              word = "";
              ++pos;
           }
           else{
               word += s[i]; //拆分单词
           }
       }
       if(pos != pattern.length()) //有多余的pattern字符
          return false;
       return true;      
       
    }    

};