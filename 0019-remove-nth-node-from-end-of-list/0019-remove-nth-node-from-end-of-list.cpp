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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return head;
        ListNode* prev=head, *lst=head;
        while(n-->0){
            lst = lst->next;
        }
        if(lst==nullptr) return head->next;
        while(lst->next){
            lst = lst->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        
        return head;
    }
};