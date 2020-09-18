class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("",result,n,n);
        return result;
    }
    
    //left  -- 还可以放入左括号的数量
    //right -- 还可以放入右括号的数量
    void generate(string item,vector<string> &result,int left, int right){
        if(left == 0 && right == 0){
            result.push_back(item);
        }

        if(left>0){  
            generate(item + "(",result,left-1,right);
        }
        if(right >0 && right > left){  //如果右括号剩余数量大于左括号
            generate(item + ")",result,left,right-1);
        }
        
    }
};