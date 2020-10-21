//两个栈来存储
class Solution {
public:
    bool backspaceCompare(string S, string T) {
       //从后往前
       int ps = S.length()-1; int countS = 0; //记录S当前的退格符号
       int pt = T.length()-1; int countT = 0; //记录T当前的退格符号
       
       while(ps>=0 || pt>=0){
          //调整ps的合法位置
          while(ps>=0){  //边界
              if(S[ps] == '#'){ //退格符
                  ++countS;
                  --ps;
              }else{
                  if(countS>0){//不是退格符但是需要退格
                     --ps;
                     --countS;
                  }else{
                     break;  //合法字符且没有退格
                  }
              } 
          }

          //调整pt的合法位置
          while(pt >= 0){  //边界
              if(T[pt] == '#'){ //退格符
                  ++countT;
                  --pt;
              }else{
                  if(countT>0){//不是退格符但是需要退格
                     --pt;
                     --countT;
                  }else{
                     break;  //合法字符且没有退格
                  }
              } 
          }
          
          //比较 ps 和 pt的位置
          if(ps>=0 && pt>=0){
              if(S[ps]!=T[pt]){
                  return false; //不相等
              }
          }else{
              if(ps>=0 || pt>=0){
                  return false; //只有一个指针遍历完了，肯定无法匹配
              }
          }
          --pt;--ps; //匹配成功，移动指针
    }
    return true;
  }

};