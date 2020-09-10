class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    //1.将x入栈
    //2.依次让头部元素出栈并入栈
    void push(int x) { 
     int size = data_queue.size();
     	data_queue.push_back(x);
     for (int i = 0; i < size; i++) {
		data_queue.push_back(data_queue.front());
		data_queue.pop_front();
	}
    }
    
    //弹出头部元素
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
      int ret = data_queue.front();
      data_queue.pop_front();
      return ret;
    }
    
    //返回头部元素
    /** Get the top element. */
    int top() {
     return data_queue.front();
    }
    
    //判断队列是否为空
    /** Returns whether the stack is empty. */
    bool empty() {
      return data_queue.empty();
    }
private:
std::deque<int> data_queue;
};