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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {}; 

        vector<vector<TreeNode*>> dp(n + 1);
        dp[1].push_back(new TreeNode(0)); 

        for (int nodes = 3; nodes <= n; nodes += 2) {
            for (int leftNodes = 1; leftNodes < nodes; leftNodes += 2) {
                int rightNodes = nodes - 1 - leftNodes;
                for (TreeNode* left : dp[leftNodes]) {
                    for (TreeNode* right : dp[rightNodes]) {
                        TreeNode* root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        dp[nodes].push_back(root);
                    }
                }
            }
        }

        return dp[n]; 
    }
};