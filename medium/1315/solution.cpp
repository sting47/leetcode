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
    bool is_exist(TreeNode* node) {
        if(node == NULL) return false;
        else return true;
    }
    
    int sumOfExistChild(TreeNode* root) {
        int total = 0;
        if(!is_exist(root)) {
            return 0;
        }
        if(is_exist(root->left)) {
            if(is_exist(root->left->left)) total++;
            if(is_exist(root->left->right)) total++;
        }
        if(is_exist(root->right)) {
            if(is_exist(root->right->left)) total++;
            if(is_exist(root->right->right)) total++;
        }
        
        return total;
    }
    
    int sumValueOfExistChild(TreeNode* root) {
        int total = 0;
        if(is_exist(root->left)) {
            TreeNode* left = root->left;
            if(is_exist(left->left)) total+=left->left->val;
            if(is_exist(left->right)) total+=left->right->val;
        }
        if(is_exist(root->right)) {
            TreeNode* right = root->right;
            if(is_exist(right->left)) total+=right->left->val;
            if(is_exist(right->right)) total+=right->right->val;
        }
        
        return total;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        if(sumOfExistChild(root) == 0) return 0;
        if(root->val % 2 == 0) {
            sum += sumValueOfExistChild(root);
        }
        sum += sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
        return sum;
    }
};
