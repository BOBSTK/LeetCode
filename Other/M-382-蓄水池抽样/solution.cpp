/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //第i个元素要以i/2的概率选择
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
       this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
       ListNode* cur = head;
       int val = 0;
       int i= 1;
       while(cur){
           int p = rand()%i;  //0 - i-1
           if(p==0){  //1/i
               val = cur->val;  //替换
           }
           ++i;
           cur = cur->next;
       }
       return val;
    }
private:
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */