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
#define pi pair<int, ListNode* >

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head, *last, *next;
        head = new ListNode(100000);
        last = head;
        priority_queue<pi, vector<pi>, greater<pi>> minh;
        
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr){
                minh.push({lists[i]->val, lists[i]});
            }
        }
        
        if(minh.size()==0){
            return nullptr;
        }
        
        while(minh.size()!=0){
            pi tmp = minh.top();
            minh.pop();
            last->next = tmp.second;
            last = last->next;
            if(tmp.second->next != nullptr){
                next = tmp.second->next;
                minh.push({next->val, next});
            }
        }
        
        return head->next;
    }
};