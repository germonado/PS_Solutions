# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        if not head.next:
            return head
        slow = head
        fast = head.next
        while fast and fast.next and fast.next.next:
            slow.val, fast.val = fast.val, slow.val
            slow = slow.next.next
            fast = fast.next.next
        if fast:
            slow.val, fast.val = fast.val, slow.val
        return head
