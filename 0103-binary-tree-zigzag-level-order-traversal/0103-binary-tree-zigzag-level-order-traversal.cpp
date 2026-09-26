class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if(root == NULL) return {};

        q.push(root);

        bool lr = true;

        while(!q.empty()) {

            int n = q.size();
            vector<int> curr;

            for(int i = 0; i < n; i++) {

                TreeNode* front = q.front();
                q.pop();

                curr.push_back(front->val);

                // Children ko normal order me queue karo
                if(front->left) {
                    q.push(front->left);
                }

                if(front->right) {
                    q.push(front->right);
                }
            }

            if(lr == false) {
                reverse(curr.begin(), curr.end());
            }

            ans.push_back(curr);

            // Next level ke liye direction change
            lr = !lr;
        }

        return ans;
    }
};