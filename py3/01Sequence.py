import sys

result = 0
number_of_one = 0
cases = 1
str_input = sys.stdin.readline()

for char in str_input:
	if char == '0':
		result += number_of_one
	elif char == '1':
		number_of_one += cases
	elif char == '?':
		result = result << 1
		result += number_of_one
		number_of_one = number_of_one << 1
		number_of_one += cases
		cases = cases << 1
	number_of_one %= 1000000007
	result %= 1000000007
	cases %= 1000000007
	
print(result)