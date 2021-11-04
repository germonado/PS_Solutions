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
        root = prev = ListNode()
        prev.next = head
        while head and head.next:
            b = head.next
            # head direct 3
            head.next = b.next
            # b moves to front
            b.next = head
            prev.next = b
            head = head.next
            prev = prev.next.next
            
        return root.next

# Recursive
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head and head.next:
            p = head.next
            head.next = self.swapPairs(p.next)
            p.next = head
            return p
            
        return head
