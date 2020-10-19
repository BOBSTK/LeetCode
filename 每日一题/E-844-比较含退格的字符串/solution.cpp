//两个栈来存储
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        for(int i=0;i<S.length();i++){
            if(S[i]!='#'){
                stack_S.push_back(S[i]);
            }else{
                if(stack_S.empty()){
                    continue;
                }else{
                    stack_S.pop_back();
                }
            }
        }

        for(int i=0;i<T.length();i++){
            if(T[i]!='#'){
                stack_T.push_back(T[i]);
            }else{
                if(stack_T.empty()){
                    continue;
                }else{
                    stack_T.pop_back();
                }
            }
        }

        if(stack_S.size()!= stack_T.size()){
            return false;
        }else{
            for(int i=0;i<stack_S.size();i++){
                if(stack_S[i] != stack_T[i])
                  return false;
            }
        }
        return true;
    }

   
private:
    vector<char> stack_S;
    vector<char> stack_T;
};