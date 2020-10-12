class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       int n = nums.size();
       if(n<k)
         return -1;
       for(int i=0;i<nums.size();i++){
           if(min_heap.size()<k){
               min_heap.push(nums[i]);
           }else if(nums[i]>min_heap.top()){
               min_heap.pop();
               min_heap.push(nums[i]);
           }
       }
       return min_heap.top();
    }
private:
    priority_queue<int,vector<int>,greater<int>> min_heap; //小顶堆
};