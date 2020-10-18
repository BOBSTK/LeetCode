class Solution {
    int rev_ind = 0;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        head->next = removeNthFromEnd(head->next, n);
        ++rev_ind;
        if(rev_ind == n) return head->next;
        return head;
    }
};

