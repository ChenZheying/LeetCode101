//
// Created by 陈哲英 on 2022/3/20.
//

#ifndef LEETCODE101_TREENODE_H
#define LEETCODE101_TREENODE_H

#endif //LEETCODE101_TREENODE_H

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
