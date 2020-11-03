class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int left = 0,right = A.size()-1; //左右指针
        //从左边找到山顶
        while(left+1<A.size() && A[left]<A[left+1])
          ++left;
        //从右边找到山顶
        while(right-1>=0 && A[right-1]>A[right])
          --right;
        //判断左右指针是否找到了同一个山顶
        return left>0 && right<A.size()-1 && left == right;
    }

};
