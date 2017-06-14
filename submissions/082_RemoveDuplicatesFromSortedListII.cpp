/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
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
  ListNode* deleteDuplicates(ListNode* head) {
    if(!head||!(head->next)) return head;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *pre = &dummy;
    ListNode *cur = head;

    while(cur){
      bool isDup = false;
      //如果发现有重复的，跳过该节点，cur指向下一个节点
      while(cur->next&&cur->val==cur->next->val){
        isDup = true;
        cur->next = cur->next->next;
      }
      //去掉重复的第一项
      if(isDup){
        ptr->next = cur->next;
        cur = cur->next;
        continue;
      }
      pre = cur;
      cur = cur->next;
    }
    return dummy.next;
  }
};
