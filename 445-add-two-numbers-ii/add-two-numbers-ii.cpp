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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> sum;

        stack<int> list1;
        stack<int> list2;

        ListNode* temp = l1;
        while(temp){
            list1.push(temp->val);
            temp = temp->next;            
        }
        temp = l2;
        while(temp){
            list2.push(temp->val);
            temp = temp->next;            
        }
        int carry = 0;
        while(!list1.empty() || !list2.empty()){
            int val1 = 0;
            int val2 = 0;
            if(!list1.empty()){
                val1 = list1.top();
                list1.pop();
            }
            if(!list2.empty()){
                val2 = list2.top();
                list2.pop();
            }
            int add = val1+val2+carry;
            carry = add/10;
            sum.push(add%10);
        }
        if(carry != 0) sum.push(carry);

        ListNode* head = new ListNode(-1);
        ListNode* curr = head;

        while(!sum.empty()){
            curr->next = new ListNode(sum.top());
            sum.pop();
            curr=curr->next;
        }
        return head->next;
    }
};