n, m, r = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = min(a)
d = max(b)
print(r % c + (r//c) * c + max(d-c, 0) * (r//c))