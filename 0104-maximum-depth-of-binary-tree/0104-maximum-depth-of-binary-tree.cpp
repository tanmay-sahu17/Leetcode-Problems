
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        // if(!root->left&&!root->right){
        //     return 1;
        // }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
         
         int maxdepth=1+max(left,right);

         return maxdepth;
    }
};