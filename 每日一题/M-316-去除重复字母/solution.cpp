#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26),num(26);
        for (char ch : s) {   //统计每个字符出现的次数
            num[ch - 'a']++;
        }
        string ret ;
        for(char ch : s){
            if(!vis[ch - 'a']){   //如果已经存在于栈中，直接排除 
               while (!ret.empty() && ret.back() > ch) {  //处理关键字符
                    if(num[ret.back() - 'a']>0){ //如果栈顶元素还有剩余
                        //修改栈顶元素的属性值并出栈
                        vis[ret.back() - 'a'] = 0; 
                        ret.pop_back(); 
                    }else{
                        break;
                    }    
               }  
               //ch 入栈  
               vis[ch - 'a'] = 1;
               ret.push_back(ch);     
            }
            num[ch - 'a'] -= 1; // ch 剩余数量 -1
        }

        return ret;
    }
};