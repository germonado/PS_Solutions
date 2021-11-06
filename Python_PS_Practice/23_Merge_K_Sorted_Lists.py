# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        head = ListNode()
        ptr = head
        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(heap,(lists[i].val, i, lists[i]))
        if len(heap) == 0:
            return None
        while heap:
            node = heapq.heappop(heap)
            idx = node[1]
            ptr.next = node[2]
            ptr = ptr.next
            if ptr.next:
                heapq.heappush(heap,(ptr.next.val, idx, ptr.next))
        return head.next
        