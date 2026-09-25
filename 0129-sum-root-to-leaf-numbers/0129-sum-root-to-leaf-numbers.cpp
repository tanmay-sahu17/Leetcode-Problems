class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }

    int solve(TreeNode* root, int path) {
        if(root == NULL) return 0;

        path = path * 10 + root->val;

        if(root->left == NULL && root->right == NULL) {
            return path;
        }

        int left = solve(root->left, path);
        int right = solve(root->right, path);

        return left + right;
    }
};