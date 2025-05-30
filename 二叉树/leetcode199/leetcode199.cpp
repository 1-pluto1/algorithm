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


// 递归解法
class Solution {
private:

    void dfs(TreeNode* node, int depth, vector<int>& ans) {
        if (node == nullptr) {
            return;
        }
        if (depth == ans.size()) { // 这个深度首次遇到
            ans.push_back(node->val);
        }
        dfs(node->right, depth + 1, ans); // 先递归右子树
        dfs(node->left, depth + 1, ans);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
}; 

// 层次遍历解法

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if (root != nullptr) que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if ( i == size - 1) res.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return res;
    }
};


