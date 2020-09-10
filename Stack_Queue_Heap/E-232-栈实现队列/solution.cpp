class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
    in_stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        check();
        int ret = out_stack.top();
        out_stack.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        check();
        return out_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
       return in_stack.empty()&&out_stack.empty();
    }

    //在pop和peek前执行
    //1.判断out_stack是否为空
    //2.若为空，则将in_stack中的数据push进out_stack
    void check(){
         if (out_stack.empty()) {
             while (!in_stack.empty()) {
		     out_stack.push(in_stack.top());
		     in_stack.pop();
	         }
         }
    }
    private:
    std::stack<int> in_stack;
    std::stack<int> out_stack;
};