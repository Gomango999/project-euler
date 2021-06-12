# 9! = 362880
# The largest sum of factorials for a 7 digit number is 2540160.
# As the number of digits increase, we can no longer match the number of digits

facs = [1,1,2,6,24,120,720,5040,40320,362880,3628800]

def fac_sum(i):
    s = str(i)
    total = 0
    for c in s:
        total += facs[int(c)]
    return total

total = 0
for i in range(100,facs[9]*7+3):
    if fac_sum(i) == i:
        print(i)
        total += i
print(total)
    



