class Solution {
public:
    int numJewelsInStones(string J, string S) {
      map<char,int> hash;
      for(int i=0;i<J.length();i++){
          hash[J[i]] = 0;
      }
      int sum = 0;
      for(int i=0;i<S.length();i++){
          if(hash.find(S[i]) != hash.end())
           ++sum;
      }
      return sum;
    }
};