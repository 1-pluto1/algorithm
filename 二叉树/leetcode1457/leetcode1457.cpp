struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dfs(TreeNode* node, array<int, 10>& p){
        if (node == nullptr) return 0;
        p[node->val] ^= 1;
        int res;
        if (!node->left && !node->right){
            res = accumulate(p.begin(), p.end(), 0) <= 1;
        } else
        {
            res = dfs(node->left, p) + dfs(node->right, p);
        }
        p[node->val] ^= 1;
        return res;
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        array<int, 10> p {};
        return dfs(root, p);
    }
};