
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        queue<TreeNode*> nodeQueue;
        vector<int> levelsums;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            int levelsum = 0;
            int levelsize = nodeQueue.size();
            for (int i = 0; i < levelsize; i++) {
                TreeNode* front = nodeQueue.front();
                nodeQueue.pop();
                levelsum += front->val;
                if (front->left)  nodeQueue.push(front->left);
                
                if (front->right)  nodeQueue.push(front->right);
                
            }
            levelsums.push_back(levelsum);
        }
        nodeQueue.push(root);
        root->val = 0; // root has no cousin 
        int levelIndex = 1;
        while (!nodeQueue.empty()) {
            int levelsize = nodeQueue.size();
            for (int i = 0; i < levelsize; i++) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                int siblingSum =
                    (currentNode->left ? currentNode->left->val : 0) +
                    (currentNode->right ? currentNode->right->val : 0);
                if (currentNode->left) {
                    currentNode->left->val = levelsums[levelIndex] - siblingSum;
                    nodeQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    currentNode->right->val =
                        levelsums[levelIndex] - siblingSum;
                    nodeQueue.push(currentNode->right);
                }
            }
            ++levelIndex;
        }
        return root;
    }
};
