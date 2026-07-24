/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummy(0,head);
        ListNode* first=head;
        ListNode* second=&dummy;

        while(first != nullptr && first->next != nullptr){
            ListNode* sec = first->next;
            ListNode* nextpair = sec->next;

            second->next=sec;
            sec->next = first;
            first->next=nextpair;

            second=first;
            first=nextpair;
        }
        return dummy.next;
    }
};