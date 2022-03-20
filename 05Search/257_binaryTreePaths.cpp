//
// Created by 陈哲英 on 2022/3/15.
//
#include <string>
#include <vector>
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    // 很明显是深度优先遍历
    void dfs(TreeNode* root, string& path, vector<string>& ans) {
        if(root == nullptr) {return;}
        if(root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(path);
            return;
        }
        path+=("->"+ to_string(root->val));
        dfs(root->left, path, ans);
        dfs(root->right, path,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == nullptr) {
            return ans;
        }
        string path = to_string(root->val);
        dfs(root->left,path,ans);
        dfs(root->right,path,ans);
        return ans;
    }
};