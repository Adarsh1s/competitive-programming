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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0,head);
        ListNode* first = head;
        ListNode* second = &dummy;
        while(first != nullptr){
            if(first->next != nullptr && first->val == first->next->val){
                while(first->next != nullptr && first->val == first->next->val){
                    first = first->next;
                }
                second->next = first->next;
            }
            else{
                second = second->next;
            }
            first = first->next;
        }
        return dummy.next;
    }
};