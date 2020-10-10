/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
          return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* meet = nullptr;
        while(fast){
            fast = fast->next;
            slow = slow->next;
            if(!fast)
              return nullptr;
            fast = fast->next;
            if(fast == slow){
                meet = fast; //相遇结点
                break;
            }       
        }
        if(!meet)          //没有环
          return nullptr;

        while(1){  
            if(head == meet)
              return head;
            head = head->next;
            meet = meet->next;
        }
    }
};