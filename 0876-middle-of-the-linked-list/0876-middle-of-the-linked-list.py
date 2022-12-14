# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = head
        while(fast.next):
            if not fast.next.next:
                return head.next
            fast = fast.next.next
            head = head.next
        return head