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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
       if(!pHead1 || !pHead2)
          return nullptr;
  
       int length_1 = CountLength(pHead1);
       int length_2 = CountLength(pHead2);
       //计算链表差并对齐链表
       int gap = length_1>=length_2 ? length_1 - length_2 : length_2 - length_1;
       if(length_1>=length_2){
           pHead1 = Move(pHead1,gap);
       }else{
           pHead2 = Move(pHead2,gap);
       }
       //找交点
       while(pHead1){
           if(pHead1 == pHead2)
               return pHead1;
           pHead1 = pHead1->next;
           pHead2 = pHead2->next;
       }
       return nullptr; //无交点      
    }
    
    //计算链表长度
    int CountLength(ListNode* root){
        int cnt = 0;
        while(root){
            ++cnt;
            root = root->next;
        }
        return cnt;
    }
    
    //将root向后移动n个位置
    ListNode* Move(ListNode* root,int n){
        while(n-- && root){
           root = root->next; 
        }
        return root;
    }
};