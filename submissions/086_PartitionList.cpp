/*
Given a linked list and a value x, partition it such that all nodes less than x
come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/*
该链表被分成两部分，一部分比x小，一部分比x大，所以可以考虑使用两个指针，分别代表两个子链表，
一开始都指向头结点。然后开始遍历，一个指针保存比x大的节点，一个指针保存比x小的节点。
最后将后一个指针指向第一个子链表的头节点即可。
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
  ListNode* partition(ListNode* head, int x) {
    if(!head||!(head->next)) return head;
    ListNode *p1 = head,*p2 = head,*pre1 = nullptr,*pre2 = nullptr;
    while(p1&&p1->val<x){
      pre1 = p1;
      p1 = p1->next;
    }
    p2 = p1->next;
    while(p2&&p2->val>=x){
      pre2 = p2;
      p2 = p2->next;
    }
  }
};
