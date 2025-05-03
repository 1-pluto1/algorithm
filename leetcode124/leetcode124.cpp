#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int ans = INT_MIN;
    int dfs(TreeNode* root){
        if (root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        int inSum = root->val + left + right;
        ans = max(ans, inSum);
        int outSum = root->val + max(0, max(left, right));
        return max(outSum, 0);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};