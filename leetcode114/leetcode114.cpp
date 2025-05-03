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
    void traversal(TreeNode* root, vector<TreeNode*> &vec){
        if (root != NULL){
            vec.push_back(root);
            traversal(root->left, vec);
            traversal(root->right, vec);
        }
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> vec;
        traversal(root, vec);
        for (int i = 1; i < vec.size(); i++){
            TreeNode* pre = vec[i - 1];
            TreeNode* cur = vec[i];
            pre->left = nullptr;
            pre->right = cur;
        }
    }
};