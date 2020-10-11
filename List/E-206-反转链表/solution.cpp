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
    ListNode* reverseList(ListNode* head) {
       if(!head)
         return nullptr;
       ListNode* new_head = head;
       while(head->next){
           ListNode* temp = head->next;
           head->next = temp->next;
           temp->next = new_head;
           new_head = temp;
       }
       return new_head;
    }
};