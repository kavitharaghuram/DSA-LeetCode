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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        int left2right=true;
        if(root==NULL)return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int levelsize=q.size();
            vector<int>row(levelsize);
            for(int i=0; i<levelsize; i++){
                TreeNode* node= q.front();
                q.pop();
                int index;
                if(left2right){
                    index=i;
                }
                else{
                    index=levelsize-1-i;
                }
                row[index]=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            left2right=!left2right;
            res.push_back(row);
        }
        return res;
    }
};