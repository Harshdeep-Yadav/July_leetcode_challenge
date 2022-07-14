class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        map<int ,int > mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;//this will put all the inorder elements in hashmap mp
        }
        
        TreeNode*root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp); //recursive call for tree building
            return root;
    }
    TreeNode *buildTree(vector<int>& preorder,int preStart,int preEnd ,vector<int>& inorder,int inStart,int inEnd,map<int,int> &mp)
    {
        if(preStart>preEnd||inStart>inEnd) return NULL;
        
        TreeNode*root=new TreeNode(preorder[preStart]); // root of the tree
        
        int inRoot=mp[root->val];
        int numLeft=inRoot-inStart;
         
        root->left=buildTree(preorder,preStart+1,preStart+numLeft,inorder,inStart,inRoot-1,mp); // for left subtree
        
        root->right=buildTree(preorder,preStart+numLeft+1,preEnd,inorder,inRoot+1,inEnd,mp); // for right subtree
    
    return root;
    }
};

// TC:- O(N),SC:- O(N)