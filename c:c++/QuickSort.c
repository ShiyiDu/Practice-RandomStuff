#include <stdio.h>

//static void MyQuickSort(int *a, int left, int right);
//static void QuickSort(int len, int arr[]);

void QuickSort(int arr[], int left, int right);
void MyQuickSort(int arr[], int length);
int Validate(int arr[], int length);
void InsertionSort(int arr[], int length);

static int calculations = 0;

int main(int argc, char *argv[]) {
	int size = 15000;
	int range = 20000;
	int test_array[size];
	
	for(int i = 0; i < size; i++){
		test_array[i] = rand() % range;
	}
	
//	MyQuickSort(test_array, size);
	InsertionSort(test_array, size);
//	for (int i = 0; i < size;i++) {
//		printf(" %d", test_array[i]);
//	}
	printf(" %d", Validate(test_array, size));
	printf("\n %d", calculations);
}

void MyQuickSort(int arr[], int length){
	QuickSort(arr, 0, length - 1);
}

void InsertionSort(int arr[], int length){
	int current = 0, temp, last = 0;
	while (current < length - 1) {
		//move back
		calculations ++;
		current = last;
		while (arr[current] <= arr[current + 1]) {
			calculations ++;
			current ++;
			if(current == length - 1) break;
		}
		if(current == length - 1) break;
		last = current;
		//move forward
		while (arr[current + 1] < arr[current]) {
			calculations ++;
			temp = arr[current + 1];
			arr[current + 1] = arr[current];
			arr[current] = temp;
			current--;
			if(current == -1) {
				current++;
				break;
			}
		}
	}
}

int Validate(int arr[], int length){
	for(int i = 0; i < length - 1; i++){
		if(arr[i] > arr[i+1]) return 0;
	}
	
	return 1;
}

//pick pivot in the middle
//void QuickSort(int arr[], int left, int right){
//	calculations++;
//	if(left >= right) return;
//	int pivot = (right + left) / 2;
//	int temp, start = left, end = right;
////	right--;
//	
//	while (left < right) {
//		calculations++;
//		while (arr[left] <= arr[pivot] && left < pivot) {
//			calculations++;
//			left++;
//		}
//		
//		while (arr[right] >= arr[pivot] && right > pivot) {
//			calculations++;
//			right--;
//		}
//		
//		temp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = temp;
//		
//		if(left == pivot) pivot = right;
//		else if(right == pivot) pivot = left;
//	}
//	
//	QuickSort(arr, start, left - 1);
//	QuickSort(arr, left + 1, end);
//	
//}

//pick pivot at the end
void QuickSort(int arr[], int left, int right){
	calculations++;
	if(left >= right) return;
	int pivot = right;
	int temp, start = left, end = right;
//	right--;
	
	while (left < right) {
		calculations++;
		while (arr[left] <= arr[pivot] && left < right) {
			calculations++;
			left++;
		}
		
		while (arr[right] >= arr[pivot] && right > left) {
			calculations++;
			right--;
		}
		
		if(left == right && left < end){
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

//void QuickSort(int len, int arr[]){
//	MyQuickSort(arr, 0, len - 1);
//}
//
//static void MyQuickSort(int *a, int left, int right)
//{
//	if(left >= right)
//	{
//		return ;
//	}
//	int i = left;
//	int j = right;
//	int key = a[left];
//	 
//	while(i < j)
//	{
//		while(i < j && key <= a[j])
//		{
//			j--;
//		}
//		 
//		a[i] = a[j];
//		 
//		while(i < j && key >= a[i])
//		{
//			i++;
//		}
//		 
//		a[j] = a[i];
//	}
//	 
//	a[i] = key;
//	MyQuickSort(a, left, i - 1);
//	MyQuickSort(a, i + 1, right);
//}