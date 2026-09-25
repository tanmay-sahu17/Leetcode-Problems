
class Solution {
public:
   map<int,int>mp;
   

   TreeNode*build(vector<int>& inorder, vector<int>& postorder,int left,int right,int &index){
      if(left > right) return NULL;
     int value=postorder[index--];
     int pos=mp[value];
     TreeNode*root=new TreeNode(value);
     root->right=build(inorder,postorder,pos+1,right,index);

     root->left=build(inorder,postorder,left,pos-1,index);

     return root;
   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int index = postorder.size() - 1;
       return build(inorder,postorder,0,inorder.size()-1,index);
        
    }
};