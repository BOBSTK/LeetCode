// 数组 perm 是前 n 个正整数的排列，因此数组 perm 的全部元素的异或运算结果即为从 1 到 n 的全部正整数的异或运算结果

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();  // n是一个奇数
        int total = 0;
        for(int i=1;i<=n+1;++i){
            total ^= i;
        }
        int odd = 0;
        for(int i=1;i<n;i+=2){
            odd ^= encoded[i];
        }
        vector<int> decoded = vector<int> (n+1,0);

        decoded[0] = odd ^ total;  // 确定 decoded[0]
        for(int i=1;i<=n;++i){
            decoded[i] = decoded[i-1] ^ encoded[i-1];
        }
        return decoded;
    }
};