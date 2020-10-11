# LeetCode

## 1、栈、队列、堆

### 1.1预备知识

> 栈

- 后进先出(LIFO)
- 基本操作
  - Top()：读栈顶元素
  - empty()：判断栈是否为o空
  - push()：入栈
  - pop()：出栈

> 二叉堆

- 最大最小完全二叉树 **优先级队列**

- 可以知道最大(小)的数据

  - Top O(1)
  - 调整 logN    插入 删除O(n)

- 使用

  ```c++
      priority_queue<int> big_heap;              //最大堆
  	priority_queue<int, std::vector<int>, std::greater<int>> small_heap; //最小堆
      //PS 也可以采用负数入栈实现最小堆
  ```

  

### 1.2 用队列实现栈 

- LeetCode 225


```c++
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
```

### 1.3用栈实现队列

- LeetCode 232

> 思路

- push(x)：
- pop()：弹出栈顶元素
- peek()：返回栈顶元素
- empty()：判断栈是否为空
- 用两个栈实现

```c++
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
```

### 1.4 包含min函数的栈

- LeetCode  155

> 思路

- push(x)：将元素压入栈中
- pop()：弹出栈顶元素
- peek()：返回栈顶元素
- getmin()：返回栈内最小元素
  1. 用一个辅助栈存储各状态最小值

```c++
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
```

### 1.5 合法的出栈序列

- LeetCode  946

> 思路

- 用一个栈模拟入栈过程

```c++
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      stack<int> order_stack;
	int n = pushed.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		order_stack.push(pushed[i]);
		while (!order_stack.empty() && order_stack.top() == popped[j]) { //如果栈顶元素和输出序列头部元素相同
			order_stack.pop();
			j++;
		}
	}
	if (order_stack.empty())
		return true;
	return false;
};
```

### 1.6 简单的计算器

- LeetCode 224

> 思路

- 用状态机的思想将字符串处理为数字栈和操作符栈

  <img src="G:\重要文件\备份\数据结构\image-20200725010240407.png" alt="image-20200725010240407" style="zoom: 80%;" />

- ```c++
  class Solution {
  public:
      int calculate (string s){
  	//状态参数
  	static const unsigned int STATE_BEGIN = 0;
  	static const unsigned int NUMBER_STATE = 1;
  	static const unsigned int OPERATION_STATE = 2;
  
  	std::stack<int> number_stack;     //数字栈
  	std::stack<char> operation_stack; //操作符栈
  
  	//初始化参数
  	long number = 0;
  	int STATE = STATE_BEGIN;
  	int compute_flag = 0;
  
  	//状态机
  	for (int i = 0; i < s.length(); i++) {
  		if (s[i] == ' ') {
  			continue;
  		}
  		switch (STATE)
  		{
  		case STATE_BEGIN:
  			if (s[i] >= '0' && s[i] <= '9') {   //是数字，应切换到NUMBER_STATE
  				STATE = NUMBER_STATE;
  			}
  			else {                             //是操作符，应切换到OPERATION_STATE
  				STATE = OPERATION_STATE;
  			}
  			--i;   //退格
  			break;
  		case NUMBER_STATE:
  			if (s[i] >= '0' && s[i] <= '9') {
  				number = number * 10 + s[i] - '0';   //获得数字
  			}
  			else {
  				number_stack.push(number);
  				if (compute_flag == 1) {
  					compute(number_stack, operation_stack); //计算
  				}
  				number = 0;
  				--i;                       //退格
  				STATE = OPERATION_STATE;   //切换状态
  			}
  			break;
  		case OPERATION_STATE: 
  			if (s[i] == '+' || s[i] == '-') {
  				operation_stack.push(s[i]);
  				compute_flag = 1;
  			}
  			else if (s[i] == '(') { //遇到(阻塞计算
  				STATE = NUMBER_STATE;
  				compute_flag = 0;
  			}
  			else if (s[i] >= '0' && s[i] <= '9') {
  				STATE = NUMBER_STATE;
  				--i;
  			}
  			else if (s[i] == ')') {
  				compute(number_stack, operation_stack);
  			}
  			break;
  		
  		}
  	}
  
  	if (number != 0) {   //如果最后一个是数字(1+1)，number不会push入数字栈循环就结束了
  		number_stack.push(number);
  		compute(number_stack, operation_stack);
  	}
  	if (number == 0 && number_stack.empty()) {
  		return 0;
  	}
  	return number_stack.top();
  }
  
      //计算一步
      void compute(std::stack<int>&number_stack, std::stack<char>&operator_stack) {
  	if (number_stack.size() < 2)
  		return;
  		int num1 = number_stack.top();
  		number_stack.pop();
  		int num2 = number_stack.top();
  		number_stack.pop();
  
  		char op = operator_stack.top();
  		operator_stack.pop();
  
  		if (op == '+') {
  			number_stack.push(num1 + num2);
  		}
  		else if (op == '-') {
  			number_stack.push(num2 - num1);
  		}
  	
      }
  
  
  };
  ```

- 更快解法//(1+(4+5+2)-3)+(6+8)

  - local作用域代表离current 字符最近的左右括号圈起来的区域
  - 变量
    - `res` 现阶段的local作用域中的和
    - `curnum` 每个被运算操作符隔开的元素
    - `sign` 和`curnum`对应
  - 每次遇到一个**左括号**就知道自己进入了一个新的**local作用域**
  - 遇到一个右括号，说明现在的作用域都处理好了，把推到栈里的没处理完的接着用作`res`
  
  ```c++
  int calculate (string st){
  	    stack<int> s;
          stack<char> ope;
          st.push_back('+'); 
          long res=0;
          long curnum = 0;
          bool sign = true;
          for(auto& cur:st){
              if(cur==' ') continue;
              if(cur=='('){
                  s.push(res);
                  if(sign) ope.push('+');  //第一个数是正的
                  else ope.push('-');
                  res = 0;
                  curnum = 0;
                  sign = true;
              }
              if(cur=='+'||cur=='-'){
                  res = sign? res+curnum: res-curnum;
                  curnum = 0;
                  sign= cur=='+';
                  
              }
              if(isdigit(cur)){
                  curnum = curnum * 10 + cur - '0';
              }
              if(cur==')'){
                  res = sign? res+curnum: res-curnum;
                  curnum = res;
                  res = s.top();
                  sign= ope.top()=='+';
                  ope.pop(); s.pop();
            }
              
          }
          return res;
  
      }
  
  ```
  

### 1.7 数组中第K大的数

- LeetCode 215

> 思路

- 用小顶堆

```c++
int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int, std::vector<int>, std::greater<int>> small_heap; //最小堆          
	for (int i = 0; i < nums.size(); i++) {
		if (small_heap.size() < k) {
			small_heap.push(nums[i]); //维护大小为K的小顶堆
		}
		else {
			if (small_heap.top() < nums[i]) { //如果堆顶小于数组中的数，pop并push
				small_heap.pop();      
				small_heap.push(nums[i]);
			}
		}
	}
    //最后小顶堆中为前K大的数，堆顶为第k大的数
	return small_heap.top();
}
```

### 1.8 数据流的中位数

- LeetCode 295
- void addNum(int num) - 从数据流中添加一个整数到数据结构中。
- double findMedian() - 返回目前所有元素的中位数。

> 思路

- 动态维护一个最大堆和最小堆，各存一半数据
- 维持最大堆的堆顶比最小堆的堆顶小
- 中位数
  - 长度为偶数：堆顶之和/2
  - 长度为奇数：更大的堆的堆顶

```c++
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
```

## 2、链表

### 2.1 预备知识

```c++
struct ListNode {
	int val;  //存储数据域
	ListNode* next; //存储下一个节点地址的指针域
};
```

### 2.2 链表逆序

- LeetCode 206

> 思路

- **依次遍历**链表节点，每遍历一个节点即**逆置**一个节点

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = nullptr;
        while(head){
            ListNode* p = head->next;
            head->next = new_head;
            new_head = head;
            head = p;
        }
        return new_head;
    }
};
```

- 迭代

  ```c++
  class Solution {
  public:
      ListNode* reverseList(ListNode* head) {
          if(!head){
              return nullptr;
          }
          ListNode* first = head;//始终指向原链表的首位元素
          ListNode* target = head->next;//始终指向即将要放到当前链表首元素之前的目标元素
          while(target != nullptr){
              first->next = target->next;
              ListNode* temp = target->next;
              target->next = head;
              head = target;
              target = temp;
          }
          return head;
      }
  };
  ```




- LeetCode 92
- 反转位置从m到n的链表

> 思路

- 注意维护几个结点

  - **pre_head** 开始逆置结点的前驱（如果存在，则最后指向逆序链表的表头）
  - **modify_list_tail** 开始逆置的结点（逆置完成后子链的尾结点）
  - **result** 最终转换后的链表结点 （如果pre_head不存在，直接返回head）
  - **head** 逆序链表的表头

  ```c++
  class Solution {
  public:
      ListNode* reverseBetween(ListNode* head, int m, int n) {
          int change_len = n - m ; //逆置长度 注意头结点
  	    ListNode* result = head;
  	    ListNode* pre_head = nullptr; //开始逆置的节点的前驱
  	while (head && --m) {  //注意头结点
  		pre_head = head;
  		head = head->next;
  	} 
  	ListNode* modify_list_tail = head; //始终指向开始节点
  	ListNode* target = head->next;  //始终指向即将要放到当前链表首元素之前的目标元素
  	while (target && change_len) {
  		modify_list_tail->next = target->next;
  		ListNode* temp = target->next;
  		target->next = head;
  		head = target;
  		target = temp;
  		change_len--;
  	}
  	if (pre_head) {
  		pre_head->next = head;
  	}
  	else {
  		result = head;
  	}
  	
  	return result;
      }
  };
  ```


### 2.3 求两个链表的交点

- LeetCode 160

> 思路

- 方法一

  - 交点是两链表第一个地址相同的节点

  ```c++
  class Solution {
  public:
      ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          //遍历A，将A的指针地址插入set
          std::set<ListNode*> st;
          while(headA){
              st.insert(headA);
              headA = headA->next;
          }
          //遍历B，在set中查找是否有相同的地址
          while(headB){
              if(st.find(headB)!=st.end()){
                  return headB;
              }
              headB = headB->next;
          }
          return nullptr;
      }
  };
  ```

- 方法二：

  - 计算链表A和链表B的长度和差值
  - 将较长的链表移动到和短链表对齐的位置
  - 同时移动headA和headB当两指针同时指向一个节点时，说明是相交的
  
  ```c++
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          int lengthA = getLength(headA);
          int lengthB = getLength(headB);
          int length = lengthA >= lengthB? lengthA-lengthB:lengthB-lengthA;
          if(lengthA > lengthB)
              headA = StartPosition(headA,length);
          else
              headB = StartPosition(headB,length);
          while(headA && headB){
              if(headA == headB){
                  return headA;
              }
              headA = headA->next;
              headB = headB->next;
          }
          return nullptr;
          
      }
      //计算链表长度
      int getLength(ListNode*head){
          int ret = 0;
          while(head){
              ++ret;
              head = head->next;
          }
          return ret;
      }
  
      //将链表对齐
      ListNode* StartPosition(ListNode *head, int m){
          while(m>0){
              head = head->next;
              --m;
          }
          return head;
      }  
  ```

### 2.4 链表求环

- LeetCode 141
- LeetCode 142

> 思路

- 思路一：

  - 遍历链表，将节点对应地址插入set

  - 插入节点前，需要在set中查找，如果发现有节点地址，即链表有环

    ```c++
    bool hasCycle(ListNode *head) {
            set<ListNode *> st;
            while(head){
                if(st.find(head)==st.end()){  //如果set中没有相同地址
                   st.insert(head);
                   head = head->next;
                }else{
                    return true;   //出现环，返回true
                }    
            }
            return false; //遍历完成没有环
        }
    ```

- 思路二：快慢指针

  - 快指针每次走两步，慢指针每次走一步

  - 如果两指针相遇，说明有环

  - <img src="E:\重要文件\重要文件\备份\数据结构\image-20200802113848230.png" alt="image-20200802113848230" style="zoom: 67%;" />

  - ```c++
    ListNode *detectCycle(ListNode *head) {
            ListNode *fast = head;    //快指针
            ListNode *slow = head;    //慢指针
            ListNode *meet = nullptr; //相遇指针
            //循环遍历
            while(fast){
                fast = fast->next;
                slow = slow->next;    //fast和slow先走一步
                if(!fast){
                   return nullptr;             //fast为空说明没有环
                }
                fast = fast->next;    //fast多走一步
                if(fast == slow){   //相遇
                     meet = fast;
                     break;
                }
            }
    
            if(meet == nullptr){
                return meet;
            }
            while(1){
                if(head == meet){
                    return head;
                }
                head = head->next;
                meet = meet->next;
            }
        }
    ```

### 2.5 链表划分

- LeetCode 86

> 思路 

- 临时头节点 less more

```c++
ListNode* partition(ListNode* head, int x) {
       //创建两个结点，用于保存<x的值和>=x的值
        ListNode *less_head=new ListNode(0);
        ListNode *more_head=new ListNode(0);
        //创建两个指针指向两个新建结点
        ListNode *less_ptr=less_head,*more_ptr=more_head;
        //遍历链表，<x的值连在before后面，>=x的值连在after后面
        while(head)
        {
            if(head->val<x)
            {
                less_ptr->next=head;
                less_ptr=head;
              
            }
            else
            {
                more_ptr->next=head;
                more_ptr=head;
            }
              head=head->next;
        }
        //将before和after连起来
        more_ptr->next=NULL;
        less_ptr->next=more_head->next;
        return less_head->next;
    }
```

### 2.6 复杂的链表的深拷贝

- LeetCode 138

> 思路

- 用Map存储节点地址和节点位置的关系

  - 原链表的random指针指向第几个节点
  
    Map：**原链表**节点地址 ->节点位置
  
  - 新链表中这个节点的地址
  
    Map：节点位置(第几个节点) -> **新链表**节点地址
  
  ```c++
  Node* copyRandomList(Node* head) {
          std::map<Node*,int> node_map; //原链表节点地址 ->节点位置
          std::vector<Node*> node_vec; //节点位置(第几个节点) -> 新链表节点地址 
          
          if(!head)
          return nullptr;
          
          int index = 0;
          Node *ptr = head;
          //第一次遍历，为map赋值
          while(ptr){
              node_map[ptr] = index++;
              //map2[index] = new Node(ptr->val);
              node_vec.push_back(new Node(ptr->val));
            ptr = ptr->next;
              //++index;
          }
          node_vec.push_back(nullptr);
          ptr = head;
          index = 0;
          //第二次遍历，连接新链表的next指针，random指针
          while(ptr){
              node_vec[index]->next = node_vec[index+1];
              if(ptr->random){
                 node_vec[index]->random = node_vec[node_map[ptr->random]];
              }
              ptr = ptr->next;
              ++index;
          }
          return node_vec[0];
         
      }
  ```
  

### 2.7 排序链表的合并

- LeetCode 21
- LeetCode 23

> 思路

- 将所有节点放到vector中，将vector排序，再讲节点顺序相连

  ```c++
  //排序函数
      bool cmp(const ListNode *a,const ListNode *b){
          return a->val < b->val;
      }
  
  ListNode* mergeKLists(vector<ListNode*>& lists) {
          std::vector<ListNode*> node_list;
          for(int i=0; i< lists.size();i++){
             ListNode*temp = lists[i];
             while(temp){
                 node_list.push_back(temp);
                 temp = temp->next;
             }
          }
          if(node_list.size() == 0){
              return nullptr;
          }
          std::sort(node_list.begin(),node_list.end(),cmp); //根据节点数值排序
          for(int i=1;i<node_list.size();i++){
              node_list[i-1]->next = node_list[i];
          }
          node_list[node_list.size()-1]->next = nullptr;
          return node_list[0];
      }
  ```

  

- 分制后相连
  
  - 对k个链表分制，两两进行合并
  
  - ```c++
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode tempHead = ListNode();
            ListNode *ptr = &tempHead;
            while(l1 && l2){
                 if(l1->val <= l2->val){
                     ptr->next = l1;
                     l1 = l1->next;
                 } else{
                     ptr->next = l2;
                     l2 = l2->next;
                 }
                 ptr = ptr->next;
            }
            if(l1){
                 ptr->next = l1;
            }
            else if(l2){
                ptr->next = l2;
            }
            return tempHead.next;
        }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if(lists.size() == 0){
             return nullptr;
         }
         if(lists.size() == 1){
             return lists[0];
         }
         if(lists.size() == 2){  //如果长度为2，合并其中的两个链表
            return mergeTwoLists(lists[0],lists[1]);
         }
         //分制
         int mid = lists.size()/2;
         std::vector<ListNode*> lists1;
         std::vector<ListNode*> lists2;
         //将链表分成两份
         for(int i=0;i<mid;i++){
             lists1.push_back(lists[i]);
         }
         for(int i=mid;i<lists.size();i++){
              lists2.push_back(lists[i]);
         }
         //对两个子链表递归
         ListNode*l1 = mergeKLists(lists1); 
         ListNode*l2 = mergeKLists(lists2);
         return mergeTwoLists(l1,l2); //将两个有序的子链表合并
        }
    
    ```

## 3、贪心算法

> 概念

- 遵循某种规律，不断贪心的选取**当前最优**策略的算法设计方法

### 3.1 分糖果

- LeetCode 455

> 思路

- 先排序

- 优先从需求因子小的孩子尝试

- ```c++
  int findContentChildren(vector<int>& g, vector<int>& s) {
          //先排序
  	sort(g.begin(), g.end());
  	sort(s.begin(), s.end());
  	//
  	int child = 0; //已经满足了几个孩子
  	int cookie = 0; //已经尝试了几个糖果
  	while (child<g.size() && cookie<s.size()) {
  		if (g[child] <= s[cookie]) {
  			++child;
  		}
  		++cookie; //无论成功失败，每个糖果只尝试一次(因为无法满足当前孩子的糖果一定无法满足下一个孩子)))
  	}
  
  	return child;
  ```

### 3.2 摇摆序列

- LeetCode 376

> 思路

- 从第一个数开始，依次找到满足摇摆序列的元素
- 当序列有一段连续的递增(或递减)时，只需要保留**首尾元素**

<img src="G:\重要文件\备份\数据结构\LeetCode\image-20200813005955970.png" alt="image-20200813005955970" style="zoom:67%;" />

- 有限状态机 只有在状态切换时增加摇摆子序列的长度

  <img src="G:\重要文件\备份\数据结构\LeetCode\image-20200813010437017.png" alt="image-20200813010437017" style="zoom:67%;" />

  ```c++
  int wiggleMaxLength(vector<int>& nums) {
          //序列个数小于2时直接为摇摆序列
          if(nums.size()<2){
              return nums.size();  
          }
          static const unsigned int BEGIN = 0;
  	    static const unsigned int UP = 1;
  	    static const unsigned int DOWN = 2;
  
          int STATE = BEGIN;
          int max_length = 1; //摇摆序列最大长度至少为1
  
          for(int i =1; i<nums.size();i++){
              switch(STATE){
                  case BEGIN:
                    if(nums[i-1] < nums[i]){
                         //切换到UP状态
                         STATE = UP;
                         ++max_length; 
                     }
                     else if(nums[i-1] > nums[i]){
                         //切换到DOWN状态
                         STATE = DOWN;
                         ++max_length;
                     }
                     break;
                  case UP:
                    if(nums[i-1]>nums[i]){
                        //切换到DOWN状态
                         STATE = DOWN;
                         ++max_length;
                    }
                    break;
                  case DOWN:
                    if(nums[i-1]<nums[i]){
                        //切换到UP状态
                         STATE = UP;
                         ++max_length;
                    }
                  break;
              }
  
          } 
  
          return max_length;
      }
  ```


### 3.3  移除K个数字

- LeetCode 402

> 思路

- 从**高位**向低位遍历：
  - 优先最高位最小，其次次高位最小...
  - 如果对应的数字大于下一位的数字，则把该位数字去掉
- 使用**栈**存储最终结果或删除工作

```c++
 string removeKdigits(string num, int k) {
      vector<int> S; //当做栈来使用，可以遍历
      string result = "";  //结果
      for(int i=0; i<num.length();i++){  //从最高位循环扫描数字num
        int number = num[i] - '0';
        //当栈不为空，栈顶元素大于数number，仍然可以删除数字时循环
        while(S.size() != 0 && k >0 && S[S.size()-1]>number){   
            S.pop_back();
            --k;
        }
        if(number!= 0 || S.size() !=0 ){  //处理0的情况
             S.push_back(number);
        }

      }
      while(S.size() != 0 && k>0){
          S.pop_back();
          --k;
      }
      for(int i = 0; i < S.size(); i++){
          //result.append(1,'0'+S[i]);
          result += ('0'+S[i]);
      }
      if(result == ""){
          result = "0";
      }

      return result;
    }
```

```c++
//用string实现的单调栈 
string removeKdigits(string num, int k) {
      string result;
	for (int i = 0; i < num.size(); i++)
	{
		while (result.size()!= 0 && k>0 &&result.back() > num[i])
		{
			result.pop_back();
			--k;
		}
          if(num[i]!= '0' ||result.size() !=0 ){  //处理0的情况
            result+=num[i];
        }
	}
    while (k > 0 && !result.empty())
	{
		result.pop_back();
		--k;
	}
	return result == "" ? "0" : result;
    }
```

### 3.4  跳跃游戏

- LeetCode 55

> 思路

- 从第0位置可以跳到第i个位置 ==> 从第0位置一定可以跳至第1,2,3,...,i-1个位置
- 跳到index[i+1]最大的位置

![image-20200818015732156](G:\重要文件\备份\数据结构\LeetCode\image-20200818015732156.png)

```c++
bool canJump(vector<int>& nums) {
      
        vector<int> index;//最远可跳的位置
        for(int i=0; i<nums.size();i++)
         index.push_back(i+nums[i]);
        int jump = 0;  //当前位置
        int max_index = index[0]; //过程中最远可到达位置

        while(jump < nums.size() && jump <= max_index){
          if(max_index < index[jump]){
              max_index = index[jump];
          }
          ++jump;
        }
        return jump>=nums.size();
       
    }


class Solution {
public:
    bool canJump(vector<int>& nums) {
      
       int k = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > k) return false;  //如果当前位置超过了你能到达的最远位置，返回false
		k = max(k, i + nums[i]); //更新最大值
        if(k>nums.size()-1) //已经达到最后一个位置了
            break;
	}
	return true;

       
    }
};
```

### 3.5 跳跃游戏II

- LeetCode 45

> 思路

- 在发现无法到达更远`current_max_index`的地方时，在这之前应该跳到一个可以到达更远位置的位置`pre_max_max_index`

> 代码

```c++
 int jump(vector<int>& nums) {
        if(nums.size() < 2) 
           return 0;   //数组长度小于2，说明不用跳跃
    
    int current_max_index = nums[0]; //当前可达的最远位置
    int pre_max_max_index = nums[0]; //遍历各个位置过程中，可达最远位置
    int jump_min = 1;
    for(int i=0; i<nums.size(); i++)
    {
          if(i > current_max_index ){ //无法再向前移动了，才进行跳跃
            jump_min++;
           current_max_index = pre_max_max_index;
        }
        if(pre_max_max_index < nums[i]+i) //更新距离最大值
            pre_max_max_index =  nums[i]+i;
    }

    return jump_min;
    }
```

### 3.6 射击气球

- LeetCode 452

> 思路

- 某个气球，至少需要一只弓箭击穿

- 在击穿这只气球的同时，**尽可能击穿更多气球**

  <img src="C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20200901002354896.png" alt="image-20200901002354896" style="zoom:80%;" />

  ```c++
  bool cmp(const vector<int> &a, const vector<int> &b){
          return a[0] < b[0];
      }
  class Solution {
  public:
    
      int findMinArrowShots(vector<vector<int>>& points) {
          if(points.size() <= 0)
          return 0;
          //对气球按左端点从小到大排序
          sort(points.begin(), points.end(), cmp);
          int shootNum = 1;
          //初始化射击区间位第一个气球的端点
          int shoot_Begin = points[0][0];
          int shoot_End = points[0][1];
          for(int i = 1;i<points.size();i++){
              if(points[i][0]<=shoot_End){    //当下一个气球的左端点在射击区间内时，有重叠
                  shoot_Begin = points[i][0];
                  if(points[i][1] < shoot_End)
                  {
                      shoot_End = points[i][1];
                  }
              }
              else{  //下一个气球与现在这个气球没有重叠，增加射击次数，重置射击区间
                  ++shootNum;
                  shoot_Begin = points[i][0];
                  shoot_End = points[i][1];
              }
          }
      return shootNum;
  
      }
  };
  ```

### 3.7 最低加油次数

- LeetCode 871

> 思路

- 如果汽车的油量足够驶向目的地，不加油
- 油用光时加油最合适
- **油量最多**的加油站加油最合适
- 每经过一个加油站，更新一下加油站最大堆
- 如果无法到达下一个加油站，则需要加油(在经过的最大油量的加油站加油)

```c++
bool cmp(const vector<int> &a, const vector<int> &b){
        return a[0] < b[0];
    }
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      if(stations.size() == 0 && startFuel<target)
      return -1;

      priority_queue<int> station_heap;  //最大堆存储经过加油站的汽油量
      stations.push_back(vector<int>{target, 0});//将终点作为特殊的加油站添加至stations
      int stop = 0; //要加几次油
      int pass = 0; //记录已经走过的距离
      sort(stations.begin(), stations.end(), cmp); //按照加油站离起点距离从小到大排序
      for(int i=0;i<stations.size();i++){
          int dis = stations[i][0] - pass; //走到当前加油站需要走的距离
          while(startFuel < dis && !station_heap.empty()){
              startFuel += station_heap.top();  //在经过的油量最多的加油站加油
              station_heap.pop(); 
              ++stop;
          }
          if(startFuel<dis && station_heap.empty()){ //油量不够驶向下一个加油站或者终点
              return -1;  
          }  
       startFuel -= dis; //减去行驶到这个加油站需要的油量
       pass += dis;      //增加行驶距离
       station_heap.push(stations[i][1]);  //将这个加油站的油量加入最大堆
      }
      return stop;
    }
};
```

## 4、递归 回溯 分治

- 递归函数（思想）
  - 结束条件
  - 递归调用
- 回溯（试探法）
  - 当探索到某一步时，发现**达不到目标**
  - **退回一步**重新选择

### 4.0 回溯

#### 4.0.1 框架

> 核心

- 实际上就是一个**决策树**的遍历过程

  1、路径：也就是已经做出的选择。

  2、选择列表：也就是你当前可以做的选择。

  3、结束条件：也就是到达决策树底层，无法再做选择的条件。

- 在**递归之前**做出选择，在**递归之后**撤销刚才的选择

> 框架

```c++
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```

#### 4.0.2 分治



### 4.1 求子集

- LeetCode 78

> 思路

- 回溯法

  - 对每个元素，都有**试探**放入和不放入集合的两个选择

    ![image-20200902010547422](E:\重要文件\重要文件\备份\数据结构\LeetCode\image-20200902010547422.png)

```c++
class Solution {
public:
    void generate(int i, vector<int>&nums,vector<int>&item,vector<vector<int>>&result){
      if(i>=nums.size())
      return;
      //放num[i]的情况
      item.push_back(nums[i]);
      result.push_back(item); //将当前结果子集加入result
      generate(i+1,nums,item,result);
      //不放num[i]的情况
      item.pop_back();
      generate(i+1,nums,item,result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; //存储最终结果
        vector<int> item; //回溯时，产生各个子集的数组
        result.push_back(item); //将空集导入result
        generate(0,nums,item,result); //计算各个子集
        return result;
    }
};
```

### 4.2 求子集II

- LeetCode 90

> 思路

- 重复
  - 同一个子集（顺序相同）
  - 同一个子集（顺序不同）
- 去重
  - 对原始nums数组**排序**
  - 使用set**去重**

```c++
1    i<vec_1.size()&&j<vec_2.size()
    2 vec_1[i]<=vec_2[j]
    3 ++J
```

### 4.3 组合数之和II

- LeetCode 40

> 思路

- 剪枝


### 4.4 生成括号

- LeetCode 22

> 思路

- 递归遍历所有结果
- 判断合法
  - 左括号和右括号数量相等
  - 左括号先于右括号

## 5、二叉树与图

- 深度优先遍历

- 广度优先遍历  **层次遍历**

  - 使用**队列**对遍历节点进行存储

- 框架

  ```c++
  void traverse(TreeNode root) {
      // root 需要做什么？在这做。
      // 其他的不用 root 操心，抛给框架
      traverse(root.left);
      traverse(root.right);
  }
  ```

- 图

  - 深度优先
  - 广度优先

### 5.1 路径之和

- LeetCode 113

> 思路

- 用**栈**存储遍历路径上的节点
- 前序遍历将结点值存入栈
-  后序遍历将节点值弹出
- 遍历到叶结点
  - 判断结果

```c++
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;  //存储结果
        vector<int> path; //存储路径
        int path_value = 0;
        traverse(root,path_value,sum,path,result);
        return result;
    }

 private:
    void traverse(TreeNode *node,int &path_value,int sum,vector<int>&path,vector<vector<int>>& result){
        if(!node)
         return;
        //更新路径
        path_value += node->val; 
        path.push_back(node->val);
        //叶子节点
        if(!node->left && !node->right && path_value==sum){
            result.push_back(path);
        }
        traverse(node->left,path_value,sum,path,result);
        traverse(node->right,path_value,sum,path,result);
        //后序操作
        path_value -= node->val;
        path.pop_back();
    }
};
```

### 5.2 最近的公共祖先

- LeetCode 236

> 思路

- 公共祖先一定在从根节点出发，到这两个节点的路径上

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> path;
        std::vector<TreeNode*> p_path;
        std::vector<TreeNode*> q_path;
        int finish = 0;
        NodePath(root,p,path,p_path,finish); //求到p的路径
        path.clear();
        finish = 0;
        NodePath(root,q,path,q_path,finish); //求到q的路径
        int path_len = 0;
        path_len = p_path.size() > q_path.size() ? q_path.size() : p_path.size(); //较短路径长度
        TreeNode *result = nullptr;
        for(int i=0;i<path_len;i++){
            if(p_path[i] == q_path[i]){
                result = p_path[i];
            }
        }
        return result;
    }

private:
    //找到给定节点的路径
    void NodePath(TreeNode *node,TreeNode * search,
    std::vector<TreeNode*>&path,  //遍历路径
    std::vector<TreeNode*>&result, //结果路径
    int &finish  //是否找到search
    ) {
    if(!node || finish==1) //如果node为空或已经找到节点，直接返回
    return;
    path.push_back(node);
    if(node == search){
      finish = 1;
      result = path; //存储路径
    }
    NodePath(node->left,search,path,result, finish);
    NodePath(node->right,search,path,result,finish);
    path.pop_back();
    }
};
```

### 5.3 二叉树就地转链表

- LeetCode 114

> 思路

- 左子树展开为链表
- 右子树展开为链表
- 连接左子树的先序最后一个结点和右子树根结点

```c++
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *last = nullptr;
        traverse(root,last);
    }
    //              当前访问节点     当前子树先序遍历的最后一个节点
    void traverse(TreeNode* node,TreeNode *&last){
        if(!node)
        return;
        //叶子节点
        if(!node->right && !node->left){
          last = node;  //当前节点是当前子树的最后一个节点
          return;
        }
        //备份左右指针
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        //左右子树的最后一个节点
        TreeNode *left_last = nullptr;
        TreeNode *right_last = nullptr;
      
      
        //如果有左子树
        if(left){
            traverse(left,left_last);  //假设左子树已经展开为链表
            node->left = nullptr;
            node->right = left;
            last = left_last; //当前节点的last保存左子树的last
        }
        //如果有右子树
        if(right){
            traverse(right,right_last); //左右子树都已展开为链表
            if(left_last){  //如果有左子树
            //将左右子树的链表连接
               left_last->right = right;
            }
            //更新当前子树的最后一个节点
            last = right_last;
        }
    }
};
```

### 5.4 二叉树的右视图

- LeetCode 199

> 思路

- 宽度优先搜索每一层最右(后)一个节点

```c++
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result; //存储结果
        std::queue<std::pair<TreeNode*,int>> Q; //宽搜队列
        if(root){ //如果根节点存在
            Q.push(std::make_pair(root,0)); //将根节点入队，层数设为1
        }
        while(!Q.empty()){
            TreeNode *node = Q.front().first; //遍历节点
            int layer = Q.front().second; //节点层数
            //出队
            Q.pop();
            //子节点入队
            if(node->left){
                Q.push(std::make_pair(node->left,layer+1));
            }
            if(node->right){
                Q.push(std::make_pair(node->right,layer+1));
            }
            //更新当前层数的最右节点
            if(result.size() == layer){   //如果是新的一层
              result.push_back(node->val);  
            }else{
              result[layer] = node->val; 
            }
            
        }
        return result;
    }
};
```

### 5.5 课程安排

- LeetCode 207

> 思路

- 课程关系可以看做有向图
  - 若无环，则可以完成课程
  - 若有环，则不可以完成课程
- 深度搜索
  - 正在搜索的顶点回到该顶点，说明有环

```c++
struct GraphNode {
	int label; //顶点值
	std::vector<GraphNode*> neighbors; //相邻节点
	GraphNode(int x) : label(x) {};  
};

bool DFS_graph(GraphNode* node, std::vector<int> &visit) {
	visit[node->label] = 0; //正在访问
    for(int i=0;i<node->neighbors.size();i++){
        if(visit[node->neighbors[i]->label] == -1){
            if(!DFS_graph(node->neighbors[i],visit)){
                return false;  //有环
            }
        }
        else if(visit[node->neighbors[i]->label] == 0){
            return false; //有环
        }
    }
    visit[node->label] = 1; //访问结束
    return true; 
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      std::vector<GraphNode *>graph; //邻接表
      std::vector<int> visit; //访问状态 -1没有访问 0正在访问 1已完成访问
      //创建图节点
      for(int i=0;i<numCourses;i++){
         graph.push_back(new GraphNode(i));
         visit.push_back(-1);
      }
      //连接顶点
      for(int i=0; i<prerequisites.size();i++){
          GraphNode *begin = graph[prerequisites[i][1]];
          GraphNode *end = graph[prerequisites[i][0]];
          begin->neighbors.push_back(end); //课程2指向课程1
      }
      for(int i=0;i<graph.size();i++){
          //如果当前节点没访问且遇到环
          if(visit[i] == -1 && !DFS_graph(graph[i],visit)){
             return false;
          }
      }
      for(int i=0; i<numCourses;i++){
          delete graph[i];
      }
      return true;
    }
};
```

- 宽度搜索
  - 只将入度为0的点添加到队列
  - 当完成一个顶点的搜索，它**指向的所有顶点**入度都减1

## 6、二分查找和二叉排序树

> 二分查找

- 假设表中元素按升序排列
- 将表**中间关键字**和**查找关键字**比较
  - 如果相等，**查找成功**
  - 利用中间位置划分
- 框架
  - 不要出现`else`，而是用`else if`写清楚
  - 计算 `mid` 时需要**防止溢出**

```c++
int binarySearch(int[] nums, int target) {
    int left = 0, right = ...;

    while(...) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            ...
        } else if (nums[mid] < target) {
            left = ...
        } else if (nums[mid] > target) {
            right = ...
        }
    }
    return ...;
}
```

> 二叉搜索树



### 6.1 搜索插入位置

- LeetCode 35

> 思路

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int position = -1;
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(target == nums[mid]){
               return mid; //返回插入位置
            }
            else if(target < nums[mid]){
                right = mid -1;
            }
              else if(target > nums[mid]){
                 left = mid +1;
            }
        }
        return right+1; //如果没有找到，插入位置
    } 
};
```



### 6.2 区间查找

- LeetCode 34

> 思路

- 分别求出**左端点**和**右端点**

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> result;
          
        //找到左端点
        result.push_back(left_bound(nums,target));
        result.push_back(right_bound(nums,target));
        return result;
    }

    //找到左端点
    int left_bound(std::vector<int>& nums,int target){
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(target == nums[mid]){
               if(mid == 0 ||target > nums[mid-1]){
                   return mid;
               }
               right = mid -1;
            }
            else if(target < nums[mid]){
                right = mid -1;
            }
              else if(target > nums[mid]){
                 left = mid +1;
            }
        }
        return -1;
    }

    //找到右端点
    int right_bound(std::vector<int>& nums,int target){
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(target == nums[mid]){
               if(mid == nums.size()-1 ||target < nums[mid+1]){
                   return mid;
               }
               left = mid + 1;
            }
            else if(target < nums[mid]){
                right = mid -1;
            }
              else if(target > nums[mid]){
                 left = mid +1;
            }
        }
        return -1;
    }
};
```

### 6.3 旋转数组查找

- LeetCode 33

> 思路

- `begin` 一定大于 `end`
- 如果`a[mid]`>`begin`说明左半区间是递增的
- 如果`a[mid]`<`begin`说明右半区间是递减的

### 6.4 二叉查找树编码与解码

- LeetCode 449

> 思路

- 前序遍历，将结果按照顺序重新构造一颗新的二叉查找树
- 新的二叉查找树与原二叉树完全一样
- 字符串和整形

### 6.5 逆序数

- LeetCode 315

> 思路

- 将元素按照原数组逆置后的顺序插入到二叉查找树中
- 在插入过程中计算多少个元素比插入元素小

## 7、哈希表和字符串

> 哈希表

- 散列表

- 把**关键字值**映射到表中一个位置**直接访问**

- **哈希函数**

- **拉链法**解决冲突

  ```c++
  struct ListNode {
  	int val;
  	ListNode* next;
  	ListNode(int x):val(x),next(nullptr){}
  };
  
  //哈希函数
  int hash_func(int key, int table_len) {
  	return key % table_len;
  }
  
  void insert(ListNode* hash_table[], ListNode* node, int table_len) {
  	int hash_key = hash_func(node->val, table_len);
  	//头插法插入结点
  	node->next = hash_table[hash_key];
  	hash_table[hash_key] = node;
  }
  
  //根据值查找结点
  bool search(ListNode* hash_table[], int value, int table_len) {
  
  	int hash_key = hash_func(value, table_len);
  	ListNode* head = hash_table[hash_key];
  	while (head) {
  		if (head->val == value) {
  			return true;
  		}
  		head = head->next;
  	}
  	return false;
  }
  
  ```

### 7.1 最长回文串

- LeetCode 409

> 思路

- 偶数字符
  - 头部出现，尾部也出现
- 奇数字符
  - 加一个中心字符

### 7.2 单词规律

- LeetCode 290

> 思路

- 拆解出一个单词时，如果该单词**已经出现**，则对应的pattern中必**出现过**对应字符
- 若该单词**未出现**，则对应的pattern中**没有出现过**对应字符
- **单词个数**与pattern中的**字符数量**相同

### 7.3 无重复字符的最长子串

- LeetCode 3

> 思路

- 枚举

  - 重复字符跳过
  - 记录当前最大字串长度

- 滑动窗口

  - 设置两个指针（i、begin）
  - 该窗口中的字串**满足题目条件**

  ```c++
  int left = 0, right = 0;
  
  while (right < s.size()) {`
      // 增大窗口
      window.add(s[right]);
      right++;
  
      while (window needs shrink) {
          // 缩小窗口
          window.remove(s[left]);
          left++;
      }
  }
  ```

## 8、动态规划

> 基础知识

- **运筹学**的一个分支

- **决策过程最优化**

- **全局最优解**

- 方法

  - 原问题与子问题
  - 动态规划状态
  - 边界状态结值
  - **状态转移方程**

- 思维框架

  ```c++
  # 初始化 base case
  dp[0][0][...] = base
  # 进行状态转移
  for 状态1 in 状态1的所有取值：
      for 状态2 in 状态2的所有取值：
          for ...
              dp[状态1][状态2][...] = 求最值(选择1，选择2...)
  ```

  

### 8.1 爬楼梯

- LeetCode 70

> 思路

- **回溯法超时**
- 到达第`i`阶楼梯，只可能从第`i-1`阶和第`i-2`阶到达
  - 第`i`阶爬法数量 = 第`i-1`阶爬法数量 + 第`i-2`阶爬法数量
- 动态规划
  - **原问题**和**子问题**：
    - 原问题：求n阶楼梯的所有走法
    - 子问题：求第1,2,3,...,n-1阶台阶的所有走法数量
  - **确认状态**
    - 第i个状态即为i阶台阶的所有走法数量
  - 边界状态的**值**
    - 第`1`阶，有1种，第`2`阶有2种
  - 状态转移方程
    - 设置**递推数组**dp[0,...,n]，`dp[i]`代表到达第`i`阶，有多少种走法
    - dp[i] = dp[i-1] + dp[i-2]

### 8.2 打家劫舍

- LeetCode 198

> 思路

动态规划

- **原问题**和**子问题**：
  - 原问题：求**最高**可盗窃金额
  - 子问题：**前i个房间**的最优解
- **确认状态**
  - 第i个状态即为前i个房间的最优解
- 边界状态的**值**
  - 前`1`个房间，第一个房间的选择
  - 前2个房间，两个房间中财富最多的
- 状态转移方程
  - 设置**递推数组**dp[0,...,n]，`dp[i]`代表前i个房间的最优解
  - dp[i] = max(dp[i-1],dp[i-2] + nums[i])

### 8.3 最大子序和

- LeetCode 53

> 思路

动态规划

- **原问题**和**子问题**：
  - 原问题：求最大子序和
  - 子问题：求以第i个数结尾的最大子序和
- **确认状态**
  - 第i个状态即为第i个数结尾的最大子序和
- 边界状态的**值**
  - 第`1`个数，nums[0]
  - 第2个数，max[nums[1]，dp[0]+nums[1]]
- 状态转移方程
  - 设置**递推数组**dp[0,...,n]，`dp[i]`代表以第`i`个数结尾的最大子序和
  - dp[i] = max(dp[i-1]+nums[i],nums[i])

### 8.4 找零钱

- LeetCode 322

> 思路

动态规划

- **原问题**和**子问题**：
  - 原问题：计算可以凑成总金额所需的**最少**的硬币个数
  - 子问题：求金额为`i`时最优解
- **确认状态**
  - 第i个状态即金额为`i`时
- 边界状态的**值**
  - 检查硬币面额，初始化dp值
- 状态转移方程
  - 设置**递推数组**dp[0,...,n]，`dp[i]`代表金额为`i`时最优解
  - dp[i] =min(dp[])

> DFS+剪枝



### 8.5 三角形最小路径和

- LeetCode 120

> 思路

- **原问题**和**子问题**：
  - 原问题：计算三角形最小路径和
  - 子问题：求从第i-1层到第i层的最优解值（从下往上）
- **确认状态**
  - 第i个状态即层数即为从i-1到i
- 边界状态的**值**
  - 第1层，为给定值
- 状态转移方程
  - 设置**递推数组**dp[0,...,n]，`dp[i]`从第i-1层到第i层的最优解
  -  dp[i] [j] = min(dp[i+1] [j],dp[i+1] [j+1]) + triangle[i] [j];

### 8.6 最长上升子序列

- LeetCode 300

> 思路

- **原问题**和**子问题**：
  - 原问题：计算最长上升子序列
  - 子问题：求以第i个数字结尾的最长上升子序列
- **确认状态**
  - 第i个状态即为第i 个数字
- 边界状态的**值**
  - 第1层，为第i个数字
- 状态转移方程
  - 设置**递推数组**dp[0,...,n]，`dp[i]`为以第i个数字结尾最优解
  - dp[i] = max(dp[j] + 1); 0<=j<i且nums[i] > nums[j]

### 8.7 最小路径和

- LeetCode 64

> 思路

![image-20200916002044344](E:\Code\LeetCode\LeetCode\笔记\LeetCode\image-20200916002044344.png)

- **原问题**和**子问题**：
  - 原问题：计算最小路径和
  - 子问题：求到达[i,j]的最优解
- **确认状态**
  - 第[i,j]个状态即为第[i,j] 个数字
- 边界状态的**值**
  - 第一行和第一列
  - dp[1,1]  = grid[1] [1] 
  - dp[1,2] = grid[1] [2]
  - dp[2,1] = grid [2] [1]
- 状态转移方程
  - 设置**递推数组**dp[m] [n] dp[i] [j] 为到达第i行第j列的最优解
  - dp[i] [j]= min(dp [i-1] [j] + grid[i] [j]  , dp[i] [j-1] + grid[i] [j])


### 8.8 地牢游戏

- LeetCode 174

> 思路

- **原问题**和**子问题**：
  - 原问题：计算最低初始健康点数
  - 子问题：求到达[i,j]的最少健康点数
- **确认状态**
  - 第[i,j]个状态即为第[i,j] 个格子
- 边界状态的**值**
  - 到达公主位置的最低健康点数
- 状态转移方程
  - 设置**递推数组**dp[m] [n] dp[i] [j] 为到达第i行第j列的最低健康点数
  - dp[i] [j]= max(1,)

### 8.9 背包问题

> 0-1 背包

- 有 **N件物品**和一个**容量**为 V的背包。第 i件物品的**费用**是 w [ i ]，**价值**是 v [ i ]，
- 求将哪些物品装入背包可使**价值总和**最大

$$
f[i][j]=max(f[i−1][j],f[i−1][j−w[i]]+v[i])
$$

```c++
for (int i = 1; i <= n; i++)
    for (int j = V; j >= w[i]; j--)
        f[j] = max(f[j], f[j - w[i]] + v[i]);
```





> 完全背包

- 有**N 种物品**和一个**容量**为V 的背包，每种物品都有**无限件**可用。第i 种物品的**费用**是w [ i ] ，**价值**是v [ i ] 。
- 求解将哪些物品装入背包可使这些物品的**费用总和**不超过背包容量，且**价值总和**最大

$$
f[i][j]=max(f[i−1][j−k∗w[i]]+k∗v[i])∣0<=k∗w[i]<=j
$$

```c++
for (int i = 1; i <= n; i++)
    for (int j = w[i]; j <= V; j++)
        f[j] = max(f[j], f[j - w[i]] + v[i]);
```



## 9、搜索

### 9.1 岛屿数量

- LeetCode 200

> 思路

- DFS
- BFS