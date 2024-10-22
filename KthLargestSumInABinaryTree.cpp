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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long> pq; // creat maximium heap 
       queue<TreeNode*>q;
       q.push(root);
       q.push(NULL);
       long long  sum = 0;
       while(!q.empty()){
            TreeNode*front = q.front();
            q.pop();
            if (front == NULL){
                pq.push(sum);
                sum = 0;
                if (!q.empty()){
                    q.push(NULL);
                }

            }
            else {
                sum += (long long )front->val;
                if(front->left){
                    q.push(front->left);
                }
                if (front->right){
                    q.push(front->right);
                }
            }
       }
       if (pq.size() < k){
        return -1;
       }
        for (int i = 0; i < k - 1; i++) pq.pop(); // remove maximum level sum for find kth largest sum 
        return pq.top();
    }
};
