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
 /*
class Solution {
    int height(TreeNode* root, int val){
        if(root == NULL){
            return -1;
        }

        int left = height(root->left,val);
        int right = height(root->right,val);

        return max(left,right) + 1; 
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
            vector<int>ans;

            for(int i = 0;i<queries.size();i++){
                ans.push_back(height(root,queries[i]));
            }      
            return ans;
    }
};
*/

class Solution {
    int maxRemoveheight[100001];
    int currMaxheight = 0;
    int height(TreeNode* root, int val){
        if(root == NULL){
            return -1;
        }

        int left = height(root->left,val);
        int right = height(root->right,val);

        return max(left,right) + 1; 
    }
    void leftToRight(TreeNode* root, int currheight){
        if(root == NULL){
            return ;
        }
        maxRemoveheight[root->val] = currMaxheight;

        currMaxheight = max(currheight,currMaxheight);
        leftToRight(root->left,currheight+1);
        leftToRight(root->right,currheight+1);

    }

    void rightToLeft(TreeNode* root,int currheight){
        if(root == NULL) return ;
        maxRemoveheight[root->val] = max(maxRemoveheight[root->val],currMaxheight);
        currMaxheight = max(currMaxheight,currheight);
        rightToLeft(root->right,currheight+1);
        rightToLeft(root->left,currheight+1);
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
            
        leftToRight(root,0);
        currMaxheight = 0;
        rightToLeft(root, 0);

        vector<int>ans;
        for(auto i:queries){
            ans.push_back(maxRemoveheight[i]);
        }

        return ans;

    }

};
