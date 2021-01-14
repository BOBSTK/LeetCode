class Solution {
public:
    // N_i = N_i-1 * 2 + A[i]
    // M_0 = N_0 % 5
    // M_i = (M_i-1 * 2 + A[i]) % 5
    // M_i = N_i % 5
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> list;
        int prefix = 0;
        int length = A.size();
        for (int i = 0; i < length; i++) {
            // prefix = ((prefix << 1) + A[i]) % 5;
            prefix = (prefix*2 + A[i]) % 5;
            list.emplace_back(prefix == 0);
        }
        return list;
    }
};