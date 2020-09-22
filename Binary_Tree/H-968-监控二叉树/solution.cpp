/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 static int NO_CAMERA = 0;  //没有摄像机，也没有被监控
 static int NO_NEED = 1;  //不需要相机
 static int HAS_CAMERA = 2 ; //有摄像机
class Solution {

public:
    int minCameraCover(TreeNode* root) {
       int res = 0;
       if(!root)
         return 0;
       if(dfs(root,res) == NO_CAMERA)
         ++res;
       return res;
    }

    int dfs(TreeNode *node,int &res){
        if(node == nullptr) //如果节点不存在=,则不需要监控
         return 1;
        if(!node->left && !node->right ) //如果是叶子节点，返回0，等待父节点监控
         return NO_CAMERA;
        int left,right; //判断左右儿子结点上是否有摄像头
        left = dfs(node->left,res);
        right = dfs(node->right,res);
        if(left == 0 || right == 0){ //如果儿子节点没有被覆盖，则在这个节点上设置摄像头
             ++res;
             return HAS_CAMERA;
        }
        return left==HAS_CAMERA || right==HAS_CAMERA ? NO_NEED : NO_CAMERA; //此节点是否放置摄像头
    }
 
};