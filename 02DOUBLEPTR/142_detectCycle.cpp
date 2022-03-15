//
// Created by 陈哲英 on 2021/11/11.
//

#include "../ListNode.h"
#include <unordered_set>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //方法1：使用一个哈希表存储已经访问到的节点，返回第二次被访问的节点，如果没有就返回null
//    ListNode *detectCycle(ListNode *head) {
//        unordered_set<ListNode* > visited;
//        while(head!= nullptr) {
//            if(visited.find(head) == visited.end()) {
//                visited.insert(head);
//                head = head->next;
//            }
//            else
//            {
//                return head;
//            }
//        }
//        return nullptr;
//
//    }
    //方法2：快慢指针，一个指针走两步，一个指针走一步
    //如果快指针走到头了，就返回null
    //否则两个指针总能碰上
    //慢指针走的长度为
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast != nullptr) {
            slow = slow -> next;
            if(fast -> next == nullptr) {
                return nullptr;
            }
            else {
                fast = fast->next->next;
                if (fast == slow) {
                    fast = head;
                    while(fast!=slow) {
                        slow = slow->next;
                        fast = fast->next;
                    }
                    return fast;
                }
            }
        }
    }

};