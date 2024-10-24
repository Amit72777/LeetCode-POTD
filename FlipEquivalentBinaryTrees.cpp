/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
               if (root1 == NULL && root2 == NULL) {
            return true;
        }
        if (root1 == NULL || root2 == NULL) {
            return false;
        }
        // If the root values are not the same, they can't be flip equivalent.
        if (root1->val != root2->val) {
            return false;
        }
        
        // Recursively check for flip equivalence:
        // Case 1: Left children are flip equivalent, and right children are flip equivalent.
        // Case 2: Left child of one is flip equivalent to right child of the other and vice versa.
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));

    }
};
