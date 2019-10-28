import sys

def CalSum(sequence):
	current_node = 1
	for i in sequence:
		if i == 'L':
			current_node = current_node << 1
		elif i == 'R':
			current_node = (current_node << 1) + 1
	return current_node
	
def GetAnswer(row_seq):
	power = 0
	seq_length = len(row_seq)
	marker = []
	
	i = 0
	for char in row_seq:
		if char == '*':
			power += 1;
			marker.append(i)
		i += 1
	del i
	
	total_seq = 3 ** power
	
	result = 0
	
	i = 0
	while i < total_seq:
		cur_filling = ToTernary(i)
		
		while len(cur_filling) < power:
			cur_filling = "0" + cur_filling
		
		cur_sequence = []
		
		j = 0
		while j < seq_length:
			cur_sequence.append(row_seq[j])
			j += 1
		
		j = 0
		while j < power:
			cur_mark = marker[j]
			temp = cur_filling[j]
			cur_sequence[cur_mark] = 'R' if temp == '0' else 'L' if temp == '1' else 'P'
			j += 1
			
		result += CalSum(cur_sequence)
		i += 1
	return result

def ToTernary(number):
	result = ""
	power_size = 1
	while 3 ** power_size <= number:
		power_size += 1
	power_size -= 1
	while power_size != -1:
		cur_place = number // (3 ** power_size)
		number %= 3 ** power_size
		result += str(cur_place)
		power_size -= 1
	return result
		
input_str = sys.stdin.readline()
print(GetAnswer(input_str))