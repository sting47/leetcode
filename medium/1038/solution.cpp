/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int bstTraverse(TreeNode* root, int sumParent) {
        int resVal = 0;
        int rightVal = 0;
        if (root->right != NULL) {
            rightVal = bstTraverse(root->right, sumParent);
        }
        else {
            rightVal += sumParent;
        }
        rightVal += root->val;

        if (root->left != NULL) {
            resVal = bstTraverse(root->left, rightVal);
            resVal -= rightVal;
        }
        root->val = rightVal;
        return resVal + rightVal;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        bstTraverse(root, 0);
        return root;
    }
};
