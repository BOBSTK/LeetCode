class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
       if (big_heap.empty()) {   //规定第一个数进入最大堆
        big_heap.push(num);
        return;
    }

    if (big_heap.size() == small_heap.size()) {  //两个堆数量一样多
        if (num >= big_heap.top()) {
            small_heap.push(num);
        }
        else {
            big_heap.push(num);
        }
    }else if (big_heap.size() >= small_heap.size()) {  //最大堆数量多
        if (num > big_heap.top()) {  //num比最大堆的堆顶大，push入最小堆
            small_heap.push(num);
        }
        else {                    //num比最大堆的堆顶小
            small_heap.push(big_heap.top());
            big_heap.pop();
            big_heap.push(num);
        }
    }else if (big_heap.size() <= small_heap.size()) {     //最小堆数量多
        if (num < small_heap.top()) {
            big_heap.push(num);
        }
        else {
            big_heap.push(small_heap.top());
            small_heap.pop();
            small_heap.push(num);
        }

    }
   } 
    
    double findMedian() {

        if(big_heap.size() == small_heap.size()){
            return (big_heap.top()+small_heap.top()) / 2.0;
        }
        return (big_heap.size()>small_heap.size()?big_heap.top():small_heap.top());
    }
    private:

     priority_queue<int> big_heap; //最大堆
     priority_queue<int, std::vector<int>, std::greater<int>> small_heap; //最小堆
};