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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode less(0), more(0);
        ListNode* l = &less;
        ListNode* m = &more;
        
        ListNode* current = head;
        while(current != nullptr){
            if(current->val < x) {
                l->next = current;
                l=l->next;
            }
            else{
                m->next = current;
                m=m->next;
            }
            current=current->next;
        }
        l->next=more.next;
        m->next=nullptr;
        return less.next;
    }
};