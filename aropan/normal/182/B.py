# map(int, raw_input().split())...
# " ".join([])...
# [0] * n...
# isupper...

d = int(raw_input())
n = int(raw_input())
ans = 0
for x in map(int, raw_input().split())[:-1]:
	ans += d - x
print ans