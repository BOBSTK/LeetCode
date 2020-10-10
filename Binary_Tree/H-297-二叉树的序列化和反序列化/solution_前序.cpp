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
        string ret ; //存储结果
        if(!root)
          return "#,";
        dfs_s(root,ret); 
        return ret;
    }

    //前序遍历转化为字符串
    void dfs_s(TreeNode* root,string &ret){
        if(!root){
            ret += "#,";
            return;
        }
        ret += to_string(root->val) + ',';
        dfs_s(root->left,ret);
        dfs_s(root->right,ret);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       int i = 0; //索引
       return dfs(data,i);
    }

     TreeNode* dfs(string& data,int &i){
         if(i >= data.size())
           return nullptr;
         if(data[i] == '#'){
             i += 2;
             return nullptr;
         }
         int value = 0, sign = 1;
         //判断符号
         if(data[i] == '-'){
             sign = -1;
             ++i;
         }
         while(data[i]!=','){
             value = value*10 + (data[i]-'0');
             ++i;
         }
         ++i;
         value *= sign;
         TreeNode *root = new TreeNode(value);
         root->left = dfs(data,i);  //左子树已经反序列化
         root->right = dfs(data,i); //右子树已经反序列化
         return root; //返回根节点
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));