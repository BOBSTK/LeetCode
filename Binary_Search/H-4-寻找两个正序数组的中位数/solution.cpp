// 寻找两个有序数组中的第 k 小的数，其中 k 为 (m+n)/2 或 (m+n)/2+1
// 二分查找
class Solution {
public:
    int GetKthElement(vector<int>& nums1, vector<int>& nums2,int k){
        int m = nums1.size();
        int n = nums2.size();
        int index_1 = 0;
        int index_2 = 0;
        while(true){
            // 越界情况
            // 返回另一个数组第k小的数 (有序)
            if(index_1 == m){
                return nums2[index_2+k-1]; 
            }
            if(index_2 == n){
                return nums1[index_1+k-1]; 
            }
            if(k==1){
                return min(nums1[index_1], nums2[index_2]);
            }

            // 正常情况
            // 新的下标
            int new_index_1 = min(index_1 + (k/2) -1,m-1);
            int new_index_2 = min(index_2 + (k/2) -1,n-1);
            if(nums1[new_index_1] <= nums2[new_index_2]){
                k -= (new_index_1 - index_1 + 1);
                index_1 = new_index_1 + 1;
            }else{
                k -= (new_index_2 - index_2 + 1);
                index_2 = new_index_2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l_1 = nums1.size();
        int l_2 = nums2.size();
        int total = l_1 + l_2; 
        if( total%2 == 0){  //偶数
            return (GetKthElement(nums1,nums2,total/2) + GetKthElement(nums1,nums2,total/2+1))/2.0;
        }else{
            return GetKthElement(nums1,nums2,total/2+1);
        }
        //cout<<GetKthElement(nums1,nums2,2);
        return 0;
    }
};