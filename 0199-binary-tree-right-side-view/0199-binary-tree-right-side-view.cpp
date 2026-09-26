class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        if(root == NULL) return {};

        queue<TreeNode*> q;
        vector<int> ans;

        q.push(root);

        while(!q.empty()) {

            int n = q.size();

            for(int i = 0; i < n; i++) {

                TreeNode* front = q.front();
                q.pop();

                if(i == n - 1) {
                    ans.push_back(front->val);
                }

                if(front->left) {
                    q.push(front->left);
                }

                if(front->right) {
                    q.push(front->right);
                }
            }
        }

        return ans;
    }
};