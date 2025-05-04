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
        bool isleaf(TreeNode* node){
            return !node->left && !node->right;
        }
        int dfs(TreeNode* node){
            int ans = 0;
            if (node->left){
                ans += isleaf(node->left) ? node->left->val : dfs(node->left);
            }
            if (node->right){
                ans += dfs(node->right);
            }
            return ans;
        }
        int sumOfLeftLeaves(TreeNode* root) {
            int ans = dfs(root);
            return ans;
        }
    };