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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size == 0)
          return nullptr;
        if(size == 1)
          return lists[0];
        if(size == 2)
          return MergeTwoList(lists[0],lists[1]);
        //
        int mid = size/2;
        vector<ListNode*> lists1;
        vector<ListNode*> lists2;
        for(int i =0;i<mid;i++){
            lists1.push_back(lists[i]);
        }
        for(int i=mid;i<lists.size();i++){
          lists2.push_back(lists[i]);
         }
        ListNode *l1 = mergeKLists(lists1);
        ListNode *l2 = mergeKLists(lists2);
        return MergeTwoList(l1,l2);
    }

    ListNode* MergeTwoList(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1 && !pHead2)
           return nullptr;
        if(!pHead1)
          return pHead2;
        if(!pHead2)
          return pHead1;
        ListNode new_head = ListNode() ; //初始化头结点
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