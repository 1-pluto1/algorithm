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
 class Solution
 {
 public:
 
     void postorder(TreeNode* root, vector<int>&  res){
         if (root == nullptr){
             return;
         }
         postorder(root->left, res);
         postorder(root->right, res);
         res.push_back(root->val);
     }
     vector<int> postorderTraversal(TreeNode *root) 
     {
         vector<int> ans;
         postorder(root, ans);
         return ans;
     }
 };