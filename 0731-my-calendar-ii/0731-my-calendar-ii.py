class MyCalendarTwo:
    def __init__(self):
        self.single = []
        self.double = []

    def getIntersectIndex(self, arr, start, end) :
        count = len(arr)
        if count == 0 :
            return None

        left = bisect.bisect_left(arr, [start, 0])
        left = max(left - 1, 0)

        for i in range(left, count) :
            if arr[i][0] >= end :
                return None
            if arr[i][1] > start :
                return i

        return None

    def book(self, start: int, end: int) -> bool:
        if self.getIntersectIndex(self.double, start, end) != None :
            # print(str(start) + ", " + str(end) + ": " + str(self.single) + ", " + str(self.double))
            return False

        left = self.getIntersectIndex(self.single, start, end)

        if left == None :
            bisect.insort_left(self.single, [start, end])
            # print(str(start) + ", " + str(end) + ": " + str(self.single) + ", " + str(self.double))
            return True

        right = left
        addToDouble = []

        for i in range(left, len(self.single)) :
            if self.single[i][0] >= end :
                break
            s = max(self.single[i][0], start)
            e = min(self.single[i][1], end)
            addToDouble.append([s, e])
            right = i

        self.single[left][0] = min(self.single[left][0], start)
        self.single[left][1] = max(self.single[right][1], end)
        del self.single[left+1:right+1]

        if len(addToDouble) > 0 :
            i = bisect.bisect_left(self.double, addToDouble[0])
            self.double[i:i] = addToDouble

        # print(str(start) + ", " + str(end) + ": " + str(self.single) + ", " + str(self.double))
        return True

# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)
