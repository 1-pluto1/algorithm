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
    vector<int> res;
    void traversal(TreeNode* root){
        if (root == nullptr) return;
        traversal(root->left);
        res.push_back(root->val);
        traversal(root->right);
    }
    bool isValidBST(TreeNode* root) {
        res.clear();
        traversal(root);
        for (int i = 1; i < res.size(); i++){
            if (res[i] <= res[i - 1]) return false;
        }
        return true;
    }
};