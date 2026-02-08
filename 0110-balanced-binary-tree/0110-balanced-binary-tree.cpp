class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        return 1 + max(l, r);
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int l = height(root->left);
        int r = height(root->right);
        if (abs(l - r) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
