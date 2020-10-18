/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = nullptr;
        while(fast && --n){
            fast = fast->next;
        }
        //找到要删除的结点
        while(fast->next){
            pre = slow;
            fast = fast->next;
            slow = slow->next;
        }
        //删除结点
        if(!pre){  //删除的是头结点
           return head->next;
        }else{
           pre->next = slow->next;
           return head;
        }
        
    }
};