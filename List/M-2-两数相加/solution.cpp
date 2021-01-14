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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr = nullptr,*head = nullptr; 
        int add = 0; //进位
        while(l1 && l2){
            //cout << "count "<<l1->val <<" add "<<l2->val<< "cur add "<<add<<endl;
            int val = l1->val + l2->val + add;
            add = val / 10;
            val = val % 10;
            if(!head){
                //cout<<"create head"<<endl;
                head = new ListNode(val);
                curr = head;
            }else{
                 curr->next = new ListNode(val);
                 curr = curr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int val = l1->val + add;
            add = val / 10;
            val = val % 10;
            curr->next = new ListNode(val);
            l1 = l1->next;
            curr = curr->next;
        }
        while(l2){
            int val = l2->val + add;
            add = val / 10;
            val = val % 10;
            curr->next = new ListNode(val);
            l2 = l2->next;
            curr = curr->next;
        }
        // 判断最后一个进位
        if(add > 0){
            curr->next = new ListNode(add);
            curr = curr->next;
        }

        return head;
    }
    
    

};