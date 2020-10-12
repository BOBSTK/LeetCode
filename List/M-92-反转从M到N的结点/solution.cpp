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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int change_len = n - m ; //逆置长度 注意头结点
	    ListNode* result = head; //结果指向头结点
	    ListNode* pre_head = nullptr; //开始逆置的节点的前驱 头结点的前驱是null
        //移动到指定位置
        while(head && --m){
            pre_head = head;
            head = head->next;
        }
        ListNode* modify_list_tail = head; //始终指向开始节点
        ListNode* target = head->next;  //始终指向即将要放到当前链表首元素之前的目标元素
        //逆序结点
        while(target && change_len){
           modify_list_tail->next = target->next;
           ListNode *temp = target->next;
           target->next = head;
           head = target;
           target = temp;
           --change_len;
        }
        if(pre_head){ //不是从头结点开始逆置的
           pre_head->next = head;
        }else{
           result = head;
        }
        return result;
    }
};