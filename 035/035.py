MAXN = 10000005
prime = [True for i in range(MAXN)]
prime[0] = prime[1] = False
for i in range(2, MAXN):
    if prime[i]:
        for j in range(i*i, MAXN, i):
            prime[j] = False


cnt = 0
for i in range(2, 1000000):
    good = True
    s = str(i)
    for j in range(len(s)):
        if not prime[int(s)]: 
            good = False
        s = s[1:] + s[0]
    if good:
        print(i)
        cnt += 1
print(cnt)


