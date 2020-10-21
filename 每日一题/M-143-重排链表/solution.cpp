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
    void reorderList(ListNode* head) {
        if(!head)
          return;
        deque<ListNode*> nodes;
        ListNode* cur = head;
        
        while(cur->next){
           nodes.push_back(cur->next);
           cur = cur->next;
        }
        cur = head;
        int count = 0; //计数，偶数取后面，奇数取前面
        ListNode* node;
        while(nodes.size()){
            if(count%2==0){
                node = nodes.back();
                nodes.pop_back();
            }else{
                node = nodes.front();
                nodes.pop_front();
            }
            ++count;
            cur->next = node;
            cur = cur->next;
        }
        cur->next = nullptr;
    }
};