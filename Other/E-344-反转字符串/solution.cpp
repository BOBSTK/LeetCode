class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() <= 1)
          return;
        int begin = 0;
        int end = s.size() -1;
        char temp;
        while(begin < end){
           temp = s[begin];
           s[begin] = s[end];
           s[end] = temp;
           ++begin;
           --end;
        }
        return;
     }
};