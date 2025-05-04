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
     
         void dfs(TreeNode* node, set<int>& st){
             if (node == nullptr){
                 return;
             }
             st.emplace(node->val);
             dfs(node->left, st);
             dfs(node->right, st);
         }
     
         int findSecondMinimumValue(TreeNode* root) {
             set<int> st;
             dfs(root, st);
             int ans = 0, index = 0;
             if(st.size() == 1) return -1;
             for(auto& i : st){
                 if(index == 2) break;
                 ans = i;
                 index ++;
             }
             return ans;
         }
     };
    


 