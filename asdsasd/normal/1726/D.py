import os
import sys 
from io import BytesIO, IOBase
 
BUFSIZE = 8192
  
class FastIO(IOBase):
    newlines = 0
  
    def __init__(self, file):
        self._fd = file.fileno() 
        self.buffer = BytesIO()  
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break  
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0 
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE)) 
            self.newlines = b.count(b"\n") + (not b)  
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1    
        return self.buffer.readline()
 
    def flush(self): 
        if self.writable: 
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)   
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

class UnionFind:
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n
        self.group = n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return
        self.group -= 1
        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return self.group

    def all_group_members(self):
        dic = {r:[] for r in self.roots()}
        for i in range(self.n):
            dic[self.find(i)].append(i)
        return dic

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())

from collections import deque

def solve():
    n, m = map(int, input().split())
    edges = [[] for _ in range(n)]
    if m <= n + 1:
        ans = []
        UF = UnionFind(n)
        for _ in range(m):
            u, v = map(int, input().split())
            u -= 1
            v -= 1
            if UF.same(u, v):
                ans.append(1)
            else:
                UF.union(u, v)
                ans.append(0)
        print(*ans, sep="")
        return

    E = []
    UF = UnionFind(n)
    se = set()
    ans = []
    for i in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        if UF.same(u, v):
            ans.append(1)
            E.append((u, v, i))
            se.add(u)
            se.add(v)
        else:
            ans.append(0)
            UF.union(u, v)
            edges[u].append((v, i))
            edges[v].append((u, i))
    
    if len(se) != 3:
        print(*ans, sep="")
        return

    
    uu, vv, ii = E[0]
    ans[ii] = 0

    queue = deque()
    queue.append(0)
    dist = [-1] * n
    bef = [-1] * n
    dist[0] = 0
    while queue:
        pos = queue.popleft()
        for npos, i in edges[pos]:
            if dist[npos] != -1:
                continue
            dist[npos] = dist[pos] + 1
            bef[npos] = i
            queue.append(npos)
    
    du = dist[uu]
    dv = dist[vv]
    if du < dv:
        uu = vv

    i = bef[uu]
    ans[i] = 1
    print(*ans, sep="")
        
    




    
    
for _ in range(int(input())):
    solve()