#include <iostream>
#include "05Search/126_wordLadder.cpp"
int main() {
    Solution so;
    string s = "tree";
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {3, 4};
    vector<string> dic = {"ale", "apple", "monkey", "plea", "abpcplaaa", "abpcllllll", "abccclllpppeeaaaa"};
    //cout<<INT32_MAX;

    vector<vector<int>> grid = {{1, 1},
                                {1, 1},
                                {1, 1}};
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'E', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> ans = so.findLadders("hit","cog", wordList);
}