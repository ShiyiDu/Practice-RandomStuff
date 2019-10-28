import sys
def factor(n):
	result = 1
	if n == 0: return 1
	for i in range(1, n+1):
		result = result * i;
	return result
	
def combinator(n, k):
	return int(factor(n) / (factor(n-k)*factor(k)))
	

n = int(sys.argv[1])
k = int(sys.argv[2])
print(combinator(n,k))