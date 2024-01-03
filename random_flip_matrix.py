class Solution:

    def __init__(self, m: int, n: int):
        self.m = m
        self.n = n
        self.total = m*n - 1
        self.used = set()
        self.rand = 0

    def flip(self) -> List[int]:
        self.rand = random.randint(0,self.total)
        
        while self.rand in self.used:
            self.rand = random.randint(0,self.total)
        
        self.used.add(self.rand)
        return ([self.rand//self.n, self.rand%self.n])

    def reset(self) -> None:
        self.used = set()


# Your Solution object will be instantiated and called as such:
# obj = Solution(m, n)
# param_1 = obj.flip()
# obj.reset()
