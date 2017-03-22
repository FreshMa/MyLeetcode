/*
Author:FreshMa
Date:17/03/22
Link:https://leetcode.com/problems/rotate-list/#/description
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/*
看到旋转k个单位，想到用快慢指针，即双指针法，
快指针一直往前走，并计数，当计数等于要移动的步数k时，慢指针开始走
等到快指针指向最后一个元素时，慢指针指到了分割点的前一个元素
将慢指针指的元素作为链表的尾，将之后的元素插入到头部，即快指针指向原头节点

还有一种思路，是将该链表头尾相连，
然后从头部开始向后找(len-k)的位置，切割链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* dummy = head;
        ListNode* fast = head;
        ListNode* slow = head;
        int count = 0;
        int len = 0;

        if(head==NULL||head->next==NULL) return head;

        //计算链表长度，k可能大于长度
        while(dummy!=NULL){
            dummy = dummy->next;
            len++;
        }
        dummy = head;

        //如果k=0,直接返回
        k %= len;
        if(k==0) return head;
        //设置快慢指针
        while(fast->next != NULL){
            if(count!=k){
                count++;
            }
            else{
                slow = slow->next;
            }
            fast = fast->next;
        }

        dummy = slow->next;
        slow->next = NULL;

        fast->next = head;
        head = dummy;
        return head;
    }
};
