class Solution {
public:
    int sum = INT_MIN;

    int maxPath(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = max(0, maxPath(root->left));
        int right = max(0, maxPath(root->right));

        
        sum = max(sum, root->val + left + right);

        // Parent ko sirf ek side ka path de sakte hain
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return sum;
    }
};