class LinkedList :
    def __init__(self) :
        self.first = Node(None)
        self.last = self.first

    def append(self, node) :
        node.prev = self.last
        self.last.next = node
        self.last = node

    def remove(self, node) :
        prev = node.prev
        next = node.next

        prev.next = next
        if next :
            next.prev = prev
        else :
            self.last = prev

class Node :
    def __init__(self, s) :
        self.prev = None
        self.next = None
        self.s = s
        self.isDistinct = True

class Solution :
    def kthDistinct(self, arr, k) :
        linkedList = LinkedList()
        nodeDict = {}

        for s in arr :
            try :
                node = nodeDict[s]
                if node.isDistinct :
                    node.isDistinct = False
                    linkedList.remove(node)
            except KeyError :
                node = Node(s)
                nodeDict[s] = node
                linkedList.append(node)

        idx = 1
        node = linkedList.first.next

        while node :
            if idx == k :
                return node.s

            idx += 1
            node = node.next

        return ""
