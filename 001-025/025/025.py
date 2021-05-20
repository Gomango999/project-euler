# 4782
a = 1
b = 0
c = 0
LIM = 10**999
i = 1
while c < LIM:
	c = a+b
	a = b
	b = c
	i+=1
print(i-1)
