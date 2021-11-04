# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        answer = None
        fast = slow = head
        while fast:
            fast = fast.next
            answer, answer.next, slow = slow, answer, slow.next
        return answer

# Recursive version
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        global ans
        ans = None
        def reverse(node):
            global ans
            if node.next is None:
                ans = node
                return node
            else:
                tmp = reverse(node.next)
                tmp.next = ListNode(node.val)
                return tmp.next
        reverse(head)
        return ans