'''
519. Random Flip Matrix

There is an m x n binary grid matrix with all the values set 0 initially. Design an algorithm to randomly pick an index (i, j) where matrix[i][j] == 0 and flips it to 1. All the indices (i, j) where matrix[i][j] == 0 should be equally likely to be returned.

Optimize your algorithm to minimize the number of calls made to the built-in random function of your language and optimize the time and space complexity.

Implement the Solution class:

Solution(int m, int n) Initializes the object with the size of the binary matrix m and n.
int[] flip() Returns a random index [i, j] of the matrix where matrix[i][j] == 0 and flips it to 1.
void reset() Resets all the values of the matrix to be 0.

'''


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
