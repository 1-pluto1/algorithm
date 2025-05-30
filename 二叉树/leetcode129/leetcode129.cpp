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
public:
    int sumNumbers(TreeNode* root, int x = 0) {
        if (root == nullptr) return 0;
        x = x * 10 + root->val;
        if (!root->left && !root->right){
            return x;
        } 
        return sumNumbers(root->left, x) + sumNumbers(root->right, x);
    }
};