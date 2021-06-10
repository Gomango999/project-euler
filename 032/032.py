# The sum of digits in a*b is approximately equal to sum of digits in a + sum of digits in b. Hence, we only look for a and b whose sum of digits is 5 or less.

def check(a, b, c):
    s = str(a) + str(b) + str(c)

    s = "".join(sorted(s))
    return s == '123456789'


sum = 0
s = set()
for i in range(1, 5):
    print("range:", 10**i, 10**(6-i))
    for a in range(1, 10**i):
        for b in range(1, 10**(6-i)):
            if check(a, b, a*b):
                print(f"{a} * {b} = {a*b}")
                s.add(a*b)

# get unique ones
sum = 0
for i in s:
    sum += i
print(sum)
