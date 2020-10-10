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
        deque<TreeNode*> nodes; //队列
        nodes.push_back(root);  //根节点入队
        int sum = 1; //记录非null结点
        while(!nodes.empty() && sum>0){
           TreeNode*node = nodes.front(); //头结点出队
           nodes.pop_front();
           if(node){//如果结点不为nullptr
               --sum;
               ret += to_string(node->val)+',';
               if(node->left){//如果左子结点存在
                   nodes.push_back(node->left);
                   ++sum;
               }else{
                   nodes.push_back(nullptr);
               }
               if(node->right){//如果右子结点存在
                   nodes.push_back(node->right);
                   ++sum;
               }else{
                   nodes.push_back(nullptr);
               }

           }else{
               ret += "#,";
           }
        }
        //ret.setLength(ret.length()-1); //去掉最后一个逗号
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       vector<string> DATA;
       int length = 0; //记录字串长度
       for(int i=0;i<data.length();i++){
           if(data[i] == ','){ //按照,分割
              DATA.push_back(data.substr(i-length,length));
              length = 0;
           }else{
               ++length;
           }
       }
       if(DATA[0] == "#")
         return nullptr;
       TreeNode *root = new TreeNode(stoi(DATA[0])); //根结点
       TreeNode *cur = root;
       deque<TreeNode*> nodes;
       nodes.push_back(root);
       int i = 0; //索引
       while(!nodes.empty()){
          cur = nodes.front();
          nodes.pop_front();
          //左子树
          if(++i >= DATA.size())
            break;
          if(DATA[i] != "#"){
              cur->left = new TreeNode(stoi(DATA[i]));
              nodes.push_back(cur->left);
          }
          //右子树
          if(++i >= DATA.size())
            break;
          if(DATA[i] != "#"){
              cur->right = new TreeNode(stoi(DATA[i]));
              nodes.push_back(cur->right);
          }      
       }
       return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));