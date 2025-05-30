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
    void bfs(TreeNode* root, int& res){
        if (root == nullptr) return;
        if (root->val % 2 == 0){
            if (root->left != nullptr) {
                res += root->left->left != nullptr ? root->left->left->val : 0;
                res += root->left->right != nullptr ? root->left->right->val : 0;
            }
            if (root->right != nullptr) {
                res += root->right->left != nullptr ? root->right->left->val : 0;
                res += root->right->right != nullptr ? root->right->right->val : 0;
            }
        }
        bfs(root->left, res);
        bfs(root->right, res);
    }


public:
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        bfs(root, res);
        return res;
    }
};