#include <stdio.h>

int main(void) {
	char result[1000001];

	char* p_result = result;
	
	while ((*p_result = getchar()) != '\n') {
		if(*p_result == '<') p_result --;
		else p_result ++;
	}
	
	*p_result = '\0';
//	char* result_writer = result_reader;
//	gets(result_reader);
//	
//	char temp = *result_reader;
//	while (temp) {
//		
//		if(temp == '<'){
//			result_writer--;
//			*result_writer = '\0';
//		}else {
//			*result_writer = temp;
//			result_writer++;
//		}
//		result_reader++;
//		temp = *result_reader;
//	}
//	
//	*result_writer = '\0';
	
	printf("%s", result);
	return 0;
}