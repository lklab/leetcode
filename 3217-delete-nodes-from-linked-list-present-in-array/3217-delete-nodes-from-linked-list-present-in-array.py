# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        numSet = set()
        for num in nums :
            numSet.add(num)
        
        prev = None
        current = head

        while current :
            if current.val in numSet :
                if prev == None :
                    head = current.next
                    current = head
                else :
                    prev.next = current.next
                    current = current.next
            else :
                prev = current
                current = current.next

        return head
