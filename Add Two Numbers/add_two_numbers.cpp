#include <iostream>
#include <cstdint>

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* solution = new ListNode();
        ListNode* l1_head = l1;
        ListNode* l2_head = l2;
        ListNode* sol_backup = solution;
        int surplus{0};
        bool exist_sur{false};
        while(l1_head != nullptr || l2_head != nullptr){
            
            if(l1_head != nullptr && l2_head != nullptr){
                sol_backup->val = l1_head->val + l2_head->val + surplus;
                l1_head = l1_head->next;
                l2_head = l2_head->next;
            } else if(l1_head == nullptr && l2_head != nullptr) {
                sol_backup->val = l2_head->val + surplus;
                l2_head = l2_head->next;   
            } else if(l1_head != nullptr && l2_head == nullptr) {
                sol_backup->val = l1_head->val + surplus;
                l1_head = l1_head->next;
            }
            if(sol_backup->val >= 10){
                surplus = sol_backup->val / 10; 
                sol_backup->val = sol_backup->val % 10;
                exist_sur = true;
            } else {
                exist_sur = false;
                surplus = 0;
            }
            if(l1_head != nullptr || l2_head != nullptr){
                sol_backup->next = new ListNode();
                sol_backup = sol_backup->next;            
            }
        }
        if(surplus != 0 && exist_sur){
            sol_backup->next = new ListNode(surplus, nullptr);
        }
        return solution;
    }
};
