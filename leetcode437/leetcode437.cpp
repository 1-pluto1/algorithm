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
private:
    unordered_map<long long, int> preSumCount;

public:
    int dfs(TreeNode* node, int targetSum, long long preSum){
        if (!node) return 0;
        preSum += node->val;
        int pathCnt = preSumCount[preSum - targetSum];

        preSumCount[preSum] += 1;
        pathCnt += dfs(node->left, targetSum, preSum) + dfs(node->right, targetSum, preSum);

        preSumCount[preSum] -= 1;
        return pathCnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        preSumCount[0] = 1;
        return dfs(root, targetSum, 0);
    }
};