class Solution {
public:

    int preIndex = 0;
    unordered_map<int, int> mp;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int left, int right) {

        if(left > right) return NULL;

        int value = preorder[preIndex++];

        TreeNode* root = new TreeNode(value);

        int pos = mp[value];

        root->left = build(preorder, inorder, left, pos - 1);

        root->right = build(preorder, inorder, pos + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};