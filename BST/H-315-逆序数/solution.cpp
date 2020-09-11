struct BSTNode{
    int val; //记录节点值
    int count; //记录右边有多少个比当前节点小的节点
    BSTNode * left;
    BSTNode * right;
    BSTNode(int x): val(x),left(nullptr),right(nullptr),count(0){}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        std::vector<int> result;  //最终逆序数组
        std::vector<BSTNode *> node_vec;  //创建的二叉查找树节点池
        std::vector<int> count; //从后向前插入过程中，比当前节点小的count_small数组
        //逆序创建结点
        for(int i=nums.size()-1;i>=0;i--){
           node_vec.push_back(new BSTNode(nums[i]));
        }
        count.push_back(0); //最后一个结点count_small为0

        for(int i=1; i<node_vec.size();i++){
            int count_small = 0;
            BST_insert(node_vec[0],node_vec[i],count_small);
            count.push_back(count_small);
        }
        for(int i=node_vec.size()-1;i>=0;i--){
           delete node_vec[i];
           result.push_back(count[i]);
        }
        return result;
    }

    void BST_insert(BSTNode* node,BSTNode* insert_node, int &count_small){
       if(insert_node->val <= node->val){
           ++(node->count); 
           if(node->left){
               BST_insert(node->left,insert_node,count_small);
           }
           else{
               node->left = insert_node;
           }
       }
       else{
           count_small += node->count +1; //插入结点比当前结点大
           if(node->right){
               BST_insert(node->right,insert_node,count_small);
           }else{
               node->right = insert_node;
           }
       }
    }
};