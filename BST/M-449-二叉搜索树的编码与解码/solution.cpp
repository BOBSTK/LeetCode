/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         string data;
         BST_preorder(root,data);
         return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0){
            return nullptr;
        }
        std::vector<TreeNode*> node_vec;
        int val =0;
        for(int i=0;i<data.length();i++){
            if(data[i] == '#'){//遇到#,说明已经读取完一个数字
               node_vec.push_back(new TreeNode(val)); 
               val = 0;
            }else{
                val = val*10 + (data[i] - '0');
            }
        }
        //构建二叉查找树
        for(int i=1;i<node_vec.size();i++){
            BST_insert(node_vec[0],node_vec[i]);
        }
        return node_vec[0];
    }
    
    //int转string
    void Int_To_String(int val, string &str_val){
       string tmp;
       while(val){
           tmp += val%10 + '0'; //遍历val，每次将最低位转换为字符串
           val = val/10;
       }
       //反转字符串
       for(int i=tmp.length()-1;i>=0;i--){
           str_val += tmp[i];
       }
       str_val += '#';
    }

    //前序遍历BST，将结果存在data中
    void BST_preorder(TreeNode *node,string &data){
       if(!node)
           return;
       string str_val;
       Int_To_String(node->val,str_val);
       data += str_val;
      
       BST_preorder(node->left,data);
       BST_preorder(node->right,data);
    }
    
    //构建二分查找树
    void BST_insert(TreeNode *node,TreeNode* insert_node){
       if(insert_node->val < node->val){
           if(node->left){
               BST_insert(node->left,insert_node);
           }
           else{
               node->left = insert_node;
           }
       }
       else{
           if(node->right){
               BST_insert(node->right,insert_node);
           }else{
               node->right = insert_node;
           }
       }
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));