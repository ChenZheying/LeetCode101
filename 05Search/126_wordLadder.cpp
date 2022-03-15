//
// Created by 陈哲英 on 2022/3/8.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    //使用map<string, vector<string>>存储各单词可以后接的所有单词
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        //利用set元素不可重复的特性创建字典，存储所有单词
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) {return ans;}
        dict.erase(endWord);
        dict.erase(beginWord);
        unordered_map<string, vector<string>> next;
        unordered_set<string> que_shorter{beginWord}, que_longer{endWord};
        bool found = false, reversed = false;
        //循环的左右：完成next哈希表的构建
        while (!que_shorter.empty()) {
            unordered_set<string> q;
            for (const auto& word: que_shorter) {
                //替换队列中单词的单个字母，看看有没有后续
                string this_word = word;
                //遍历替换取出的单词的字母
                for (int i = 0; i < this_word.size(); ++i) {
                    char origin_char = this_word[i];
                    //将字母遍历替换为26个英文字母
                    //就替换位置i上的字母
                    for (int j = 0; j < 26; ++j) {
                        this_word[i] = j + 'a';
                        //此时取出的单词有一个字母被替换为了另一个字母(也有可能是原字母)
                        //在从尾端开始的队列中找到了当前这个单词替换一个字母后的结果
                        if (que_longer.count(this_word)) {
                            //如果交换过两个队列了，那么que_shorter队列就是包含endWord的那个队列
                            //所以当前的这个word是出自从后往前的那个队列，所以找到的this_word是word的前置元素
                            reversed?
                            next[this_word].push_back(word):
                            //替换前的原单词的next序列增加一个
                            next[word].push_back(this_word);

                            found = true;
                        }
                        //在字典中找到了当前这个单词替换一个字母后的结果
                        if (dict.count(this_word)) {
                            reversed?
                            next[this_word].push_back(word):
                            next[word].push_back(this_word);

                            //q里面保存的是在字典里找到的替换了一个字母的单词
                            q.insert(this_word);
                        }
                    }
                    //还原this_word，重新替换单词的另一个位置的字母
                    this_word[i] = origin_char;
                }
            }
            // found 表示在另一个队列中找到了当前遍历队列中的next
            // 两个队列已经连起来了，就不用
            if (found) {break;}


            //没有在que_longer中找到任何一个替换单个字母的单词
            //将在字典中找到的替换单个字母的单词删掉，
            // 并直接把que_shorter或者que_longer替换为q，
            // 这样q中的这些元素也进入了循环中，在字典中删去它们的操作保证了不重复统计
            // q中的所有元素都已经进入了next中，成为某个单词的下一个元素，
            // 由于在进行遍历时是进行的广度优先搜索，所以元素优先作为"层数"低的单词的next
            for (const auto& w: q) {
                dict.erase(w);
            }
            //没有在que_longer中找到任何一个替换单个字母的单词
            //在词典中找到替换单个字母单词的次数，比que_longer的元素个数少
            //这个ifelse的作用是：保证que_shorter是更短的那个，以减少循环次数
            if(q.size() <= que_longer.size()) {
                que_shorter = q;
            } else {
                reversed = !reversed;
                que_shorter = que_longer;
                que_longer = q;
            }
        }
        //循环结束，next构建完毕
        if (found) {
            vector<string> path = {beginWord};
            backtracking(beginWord, endWord, next, path, ans);
        }
        return ans;
    }

    //path表示当前检查得到的单词序列，ans表示条件达到时得到的最后答案
    void backtracking (const string& src, const string& dst, unordered_map<string, vector<string>>& next,
                       vector<string>& path, vector<vector<string>>& ans) {
        if (src == dst) {
            ans.push_back(path);
            return;
        }
        for (const auto& s:next[src]) {
            path.push_back(s);
            backtracking(s,dst,next,path,ans);
            path.pop_back();

        }

    }



};