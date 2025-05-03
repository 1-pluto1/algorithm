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
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
            if (preorder.size() == 0) return nullptr;

            int rootValue = preorder[0];
            TreeNode* root = new TreeNode(rootValue);

            if (preorder.size() == 1) return root;

            int delimeterIndex;
            for (delimeterIndex = 0; delimeterIndex < inorder.size(); delimeterIndex++){
                if (inorder[delimeterIndex] == rootValue) break;
            }

            vector<int> leftInorder(inorder.begin(), inorder.begin() + delimeterIndex);
            vector<int> rightInorder(inorder.begin() + delimeterIndex + 1, inorder.end());

            vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
            vector<int> rightPreorder(preorder.begin() + 1 + leftInorder.size(), preorder.end());

            root->left = traversal(leftPreorder, leftInorder);
            root->right = traversal(rightPreorder, rightInorder);

            return root;
    }
    

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0 || preorder.size() == 0) return nullptr;
        return traversal(preorder, inorder);
    }
};