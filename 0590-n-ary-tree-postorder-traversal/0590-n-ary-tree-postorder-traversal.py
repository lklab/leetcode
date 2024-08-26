"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if not root :
            return []

        stack = []
        stack.append((root, 0))
        result = []

        while stack :
            current, idx = stack.pop()

            if len(current.children) > idx :
                stack.append((current, idx + 1))
                stack.append((current.children[idx], 0))
            else :
                result.append(current.val)

        return result
