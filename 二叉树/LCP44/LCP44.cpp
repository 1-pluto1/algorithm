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
        void dfs(TreeNode* node, unordered_set<int>& set){
            if (node == nullptr){
                return;
            }
            set.emplace(node->val);
            dfs(node->left, set);
            dfs(node->right, set);
        }
        int numColor(TreeNode* root) {
            unordered_set<int> set;
            dfs(root, set);
            return set.size();
        }
    };