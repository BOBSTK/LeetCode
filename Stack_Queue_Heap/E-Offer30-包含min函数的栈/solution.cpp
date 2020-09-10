class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        data_stack.push(x);
        if(min_stack.empty()){  //如果辅助栈为空，直接push
            min_stack.push(x);
        }
        else{
            if(x>min_stack.top()) //如果x大于最小值，push最小值
            x = min_stack.top();  
            min_stack.push(x);    //否则pushx
        }
        
    }
    
    void pop() {
        data_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return data_stack.top();

    }
    
    int min() {
        return min_stack.top();
 
    }
    private:
     stack<int>data_stack;
     stack<int>min_stack;
};