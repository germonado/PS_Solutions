# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        answer = ListNode()
        if l1 is None and l2 is None:
            return None
        head = answer
        if l1 is not None and l2 is not None:
            if l1.val >= l2.val:
                answer.val = l2.val
                l2 = l2.next
            else:
                answer.val = l1.val
                l1 = l1.next

        elif l1 is None and l2 is not None:
            answer = l2
            return answer
        elif l1 is not None and l2 is None:
            answer = l1
            return answer
        while l1 or l2:
            if l1 is not None and l2 is not None:
                if l1.val >= l2.val:
                    answer.next = ListNode(l2.val, None)
                    l2 = l2.next
                else:
                    answer.next = ListNode(l1.val, None)
                    l1 = l1.next
                answer = answer.next
            elif l1 is None and l2 is not None:
                answer.next = l2
                l2 = None
            elif l2 is None and l1 is not None:
                answer.next = l1
                l1 = None
        return head            