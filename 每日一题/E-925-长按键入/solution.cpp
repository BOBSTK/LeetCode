class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int pn = 0;  //name指针
        int pt = 0;  //typed指针
        while(pn<name.length() && pt<typed.length()){
            if(typed[pt] != name[pn]){ //输入不相等
               if(pt == 0 || typed[pt]!=typed[pt-1]){ //如果pn=0 或 不是重复输入
                      return false;
               }else{
                   //跳过重复字符
                   while(typed[pt] == typed[pt-1]){
                        if(pt == typed.length()-1) //到达边界
                            return false;
                        ++pt;//移动指针
                   }
                   if(typed[pt] != name[pn]) //不相等
                     return false;
               }
            }
            //匹配成功指针移动
            ++pn;
            ++pt;
        }

        if(pn==name.length() && pt == typed.length()){
           return true;   
        }else if(pt < typed.length()){ //pt没有到头
           while(pt+1<typed.length()){
               if(typed[pt]!=typed[pt+1])
                 return false;
               ++pt;
           }
           return true;
        }else{
            return false;  //pt没有走到头
        }
    }
};