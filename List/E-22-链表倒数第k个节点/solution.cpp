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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head){
            return nullptr;
        }
        ListNode* first = head; //快指针
        while(k>0){  //快指针先移动
           first = first->next;
           k--;
           if(!first && k>0){
               return nullptr;
           }
        }
        //快慢指针一起移动
        while(first){
        first = first->next;
        head = head->next;
        }
        return head;
    }
};