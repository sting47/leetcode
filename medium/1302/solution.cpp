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
    int gLayer = 0;
    int gCurDepLayer = 0;
public:
    int deepestLeavesSum(TreeNode* root) {
        int leftSum = 0, leftLayer = 0;
        int rightSum = 0, rightLayer = 0;
        int currentLayer = 0;
        
        gLayer++;
        currentLayer = gLayer;
        
        // root is null, means another branch of parent node go deeper
        // gLayer go back one layer for another branch comparison
        if (root == NULL) {
            gLayer--;
            gCurDepLayer = gLayer;
            return 0;
        }
        
        // both child are null, means root is the deepest node of current branch
        if (root->left == NULL && root->right == NULL) {
            gCurDepLayer = gLayer;
            return root->val;
        }
        
        // recursive search sum of deepest node
        leftSum  = deepestLeavesSum(root->left);
        leftLayer = gCurDepLayer;
        gLayer = currentLayer;
        rightSum = deepestLeavesSum(root->right);
        rightLayer = gCurDepLayer;
        gLayer = currentLayer;
        
        if (leftLayer > rightLayer) {
            gCurDepLayer = leftLayer;
            return leftSum;
        }
        else if (leftLayer < rightLayer) {
            gCurDepLayer = rightLayer;
            return rightSum;
        }
        else {
            gCurDepLayer = leftLayer;
            return leftSum + rightSum;
        }
    }
};
