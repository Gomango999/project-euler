
def gcd(x, y):
   while(y):
       x, y = y, x % y
   return x

x = 1
y = 1

for a in range(10, 100):
    for b in range(a+1, 100):
        if sorted(str(a)) == sorted(str(b)):
            continue # both cancelable
        if a % 10 == 0 and b % 10 == 0:
            continue # trivial example

        # get cancelable number
        e = sorted(str(a))
        f = sorted(str(b))
        common = -1
        if e[0] == f[0]:
            common = 0
        elif e[1] == f[1]:
            common = 1
        if common == -1:
            continue # not cancelable

        # simplify fraction
        g = gcd(a, b)
        c = a // g
        d = b // g

        if c // 10 > 0:
            continue # simplification has to be one digit numerator
        if d // 10 > 0:
            continue # simplification has to be one digit denominator

        e.remove(f[common])
        f.remove(f[common])

        if c * int(f[0]) == d * int(e[0]):
            print(f"{a} / {b} = {e[0]} / {f[0]}")
            x *= c
            y *= d

g = gcd(x, y)
x //= g
y //= g
print(x, y)
