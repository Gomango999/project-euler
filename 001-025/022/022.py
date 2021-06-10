# 
from functools import reduce
with open("in.txt") as f:
    l = map(lambda s : s.strip("\"\n"), f.readline().split(","))
    l = sorted(l)
    l = list(map(lambda s : reduce(lambda p , c: int(ord(c)-ord('A')+1)+int(p) , s, 0), l))
    for i in range(len(l)):
        l[i] = l[i] * (i+1);
    print(sum(l))
