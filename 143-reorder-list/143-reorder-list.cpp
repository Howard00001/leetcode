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
    void reorderList(ListNode* head) {
        deque<ListNode*> q;
        ListNode *tmp = head;
        while(tmp!=nullptr){
            q.push_back(tmp);
            tmp = tmp->next;
        }
        tmp=head;
        while(!q.empty()){
            tmp->next=q.front();
            tmp = tmp->next;
            q.pop_front();
            if(q.empty()) break;
            tmp->next=q.back();
            tmp = tmp->next;
            q.pop_back();
        }
        tmp->next=nullptr;
    }
};