import sys

result = 1
cases = 1

for char in sys.stdin.readline():
	if char == 'P':
		continue
		
	if char == 'L':
		result = result << 1
	elif char == 'R':
		result = (result << 1) + cases
	elif char == '*':
		result = result + (result << 2) + cases
		cases *= 3
		
print(result)