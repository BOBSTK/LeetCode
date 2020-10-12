/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1 && !pHead2)
           return nullptr;
        if(!pHead1)
          return pHead2;
        if(!pHead2)
          return pHead1;
        ListNode new_head = ListNode(0) ; //初始化头结点
        ListNode* cur = &new_head;
        while(pHead1&&pHead2){
            if(pHead1->val <= pHead2->val){
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }else{
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
       //剩余部分
       while(pHead1){
           cur->next = pHead1;
           pHead1 = pHead1->next;
           cur = cur->next;
       }
       while(pHead2){
           cur->next = pHead2;
           pHead2= pHead2->next;
           cur = cur->next;
       }
       return new_head.next;
    }
};