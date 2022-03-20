#include <iostream>
#include "05Search/257_binaryTreePaths.cpp"
int main() {
    Solution so;
    TreeNode root(1), two(2), three(3), five(5);
    root.left = &two;
    root.right = &three;
    two.right = &five;
    so.binaryTreePaths(&root);

}