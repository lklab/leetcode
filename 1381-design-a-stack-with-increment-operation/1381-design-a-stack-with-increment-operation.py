class CustomStack:
    def __init__(self, maxSize: int):
        self.stack = [0] * maxSize
        self.maxSize = maxSize
        self.current = 0

    def push(self, x: int) -> None:
        if self.current >= self.maxSize :
            return

        self.stack[self.current] = x
        self.current += 1

    def pop(self) -> int:
        if self.current <= 0 :
            return -1

        self.current -= 1
        return self.stack[self.current]

    def increment(self, k: int, val: int) -> None:
        for i in range(0, min(self.current, k)) :
            self.stack[i] += val

# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)