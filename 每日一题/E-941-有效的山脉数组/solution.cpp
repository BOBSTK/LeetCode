class Solution {
public:
    bool validMountainArray(vector<int>& A) {
       if(A.size()<3)
        return false;
       if(A[1]<A[0])
        return false; //初始为上升状态
       int flag = 1; //1-上升 0-下降
       for(int i=1;i<A.size();i++){  //从1开始
         if(A[i]==A[i-1])
           return false;
         if(flag){  //上升
            if(A[i]<A[i-1])
              flag = 0; //切换到下降状态
         }else{
            if(A[i]>A[i-1])
             return false;
         }
       }
       return flag == 0; //如果以下降状态结束，返回true，否则返回false
    }

};
