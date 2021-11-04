# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        answer, head = ListNode(), ListNode()
        tmp = answer
        while l1 or l2:
            if l1 is not None and l2 is not None:
                head = ListNode((l1.val + l2.val) % 10)
                if l1.val + l2.val >= 10:
                    if l1.next:
                        l1.next.val += 1
                    elif l2.next:
                        l2.next.val += 1
                    else:
                        l1.next = ListNode(1)
                l1, l2 = l1.next, l2.next
            elif l1 is None and l2 is not None:
                head = ListNode(l2.val % 10)
                if l2.val >= 10:
                    if l2.next:
                        l2.next.val += 1
                    else:
                        l2.next = ListNode(1)
                l2 = l2.next
            elif l1 is not None and l2 is None:
                head = ListNode(l1.val % 10)
                if l1.val >= 10:
                    if l1.next:
                        l1.next.val += 1
                    else:
                        l1.next = ListNode(1)
                l1 = l1.next
            else:
                break
            answer.next = ListNode(head.val)
            answer = answer.next
        return tmp.next