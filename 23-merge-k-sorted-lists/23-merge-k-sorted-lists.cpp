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
typedef pair<int,ListNode *> node;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<node,vector<node>,greater<node>>q;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
            {
                q.push({lists[i]->val,lists[i]});
            }
        }
        ListNode *head=NULL,*tmp;
        while(!q.empty())
        {
            auto p=q.top();
            q.pop();
            if(!head)
            {
                head=p.second;
            }
            else
            {
                tmp->next=p.second;
            }
            tmp=p.second;
            if(p.second->next)
            {
                q.push({p.second->next->val,p.second->next});
            }
        }
        return head;
    }
};