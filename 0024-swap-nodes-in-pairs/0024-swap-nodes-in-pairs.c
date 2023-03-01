/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* first, *second, *tmp;
    first = head;
    if(!head || !(head->next)) return head;
    head = head->next;
    second = head;
    first->next = second->next;
    second->next = first;
    while(first->next && first->next->next){
        tmp = first;
        first = tmp->next;
        second = tmp->next->next;
        first->next = second->next;
        second->next = first;
        tmp->next = second;
    }
    return head;
}