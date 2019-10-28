#include <stdio.h>
#include <stdlib.h>
 
void swap(int *a, int *b);
//void adjustHeap(int param1,int j, int inNums[]);
//void HeapSort(int nums, int inNums[]);
void QuickSort(int arr[], int left, int right);
void MyQuickSort(int arr[], int length);

//void adjustHeap(int param1, int j, int inNums[])
//{
//	int temp=inNums[param1];
//	for (int k=param1*2+1;k<j;k=k*2+1)
//	{
//	
//		if (k+1<j && inNums[k]< inNums[k+1])
//		{
//			k++;
//		}
//
//		if (inNums[k]>temp)
//		{
//			inNums[param1]=inNums[k];
//			param1=k;
//		}
//		else
//			break;
//	}
//	inNums[param1]=temp;
//}
//
//void HeapSort(int nums,int inNums[])
//{
//
//	for (int i=nums/2-1;i>=0;i--)
//	{
//		adjustHeap(i,nums,inNums);
//	}
//
//	for (int j=nums-1;j>0;j--)
//	{
//		int temp=inNums[0];
//		inNums[0]=inNums[j];
//		inNums[j]=temp;
// 
//		adjustHeap(0,j,inNums);
//	}
//}

void MyQuickSort(int arr[], int length){
	QuickSort(arr, 0, length - 1);
}

void QuickSort(int arr[], int left, int right){
	if(left >= right) return;
	int pivot = right;
	int temp, start = left, end = right;
	right--;
	
	while (left < right) {
		while (arr[left] <= arr[pivot] && left < end) {
			left++;
		}
		
		while (arr[right] >= arr[pivot] && right > left) {
			right--;
		}
		
		if(left == right){
			temp = arr[left];
			arr[left] = arr[pivot];
			arr[pivot] = temp;
		}else if(left < right){
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}
	
	QuickSort(arr, start, left - 1);
	QuickSort(arr, left + 1, end);
	
}

int SearchNearest(int sorted[], int low, int high, int can_size){
	while (low <= high) {
		if(low == high) return sorted[low];
		int middle = (low + high) / 2;
		int middle_element = sorted[middle];
		if(middle == 0) return middle_element;
		if(can_size == middle_element){
			return middle_element;
		}else if(middle_element > can_size && can_size > sorted[middle - 1]){
			return middle_element;
		}else if(can_size < middle_element){
			high = middle - 1;
		}else if(can_size > middle_element){
			low = middle + 1;
		}
	}
	return 0;
}

int main(void) {
	int number_of_size, number_of_color;
	long long int result;
	scanf("%d %d", &number_of_size, &number_of_color);
	int all_size[number_of_size];
	int all_color[number_of_color];
	for (int i = 0; i < number_of_size; i++) {
		scanf("%d", &all_size[i]);
	}
	
	for (int i = 0; i < number_of_color; i++) {
		scanf("%d", &all_color[i]);
	}
	
	result = 0;
	
	int len = sizeof(all_size) / sizeof(int);
	MyQuickSort(all_size, len);
	
	for (int i = 0; i < number_of_color; i++) {
		int current_color = all_color[i];
		int can_size = SearchNearest(all_size, 0, number_of_size - 1, current_color);
		result += can_size-current_color;
	}
	
	printf("%lld", result);
}