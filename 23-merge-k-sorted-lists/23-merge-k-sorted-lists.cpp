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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head, *min, *last;
        int mini;
        head = new ListNode(100000);
        last = head;
        while(!lists.empty()){
            min = head;
            mini = -1;
            for(int i=0;i<lists.size();i++){
                if(lists[i]==nullptr){
                    continue;
                }
                if(min->val > lists[i]->val){
                    min = lists[i];
                    mini = i;
                }
            }
            if(mini==-1){
                break;
            }
            last->next = min;
            last = min;
            if(min->next!=nullptr){
                lists[mini] = min->next;
            }
            else{
                lists.erase(lists.begin()+mini);
            }
            min->next = nullptr;
        }
        
        return head->next;
    }
};