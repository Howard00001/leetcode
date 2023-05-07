/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1=headA, *t2=headB;
        int count=0;
        while(t1!=t2){
            if(t1->next) t1=t1->next;
            else{
                if(count==2) return nullptr;
                t1 = headB;
                count++;
            }
            if(t2->next) t2=t2->next;
            else{
                if(count==2) return nullptr;
                t2 = headA;
                count++;
            }
        }
        return t1;
    }
};