#include <stdlib.h>
#include <stdio.h>

static void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex);
static void MyMergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex);
void MergeSort(int length, int arr[]);

static void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
	int i = startIndex, j=midIndex+1, k = startIndex;
	while(i!=midIndex+1 && j!=endIndex+1)
	{
		if(sourceArr[i] > sourceArr[j])
			tempArr[k++] = sourceArr[j++];
		else
			tempArr[k++] = sourceArr[i++];
	}
	while(i != midIndex+1)
		tempArr[k++] = sourceArr[i++];
	while(j != endIndex+1)
		tempArr[k++] = sourceArr[j++];
	for(i=startIndex; i<=endIndex; i++)
		sourceArr[i] = tempArr[i];
}
 
//内部使用递归
static void MyMergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
	int midIndex;
	if(startIndex < endIndex)
	{
		midIndex = startIndex + (endIndex-startIndex) / 2;//避免溢出int
		MyMergeSort(sourceArr, tempArr, startIndex, midIndex);
		MyMergeSort(sourceArr, tempArr, midIndex+1, endIndex);
		Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
	}
}
 
void MergeSort(int length, int arr[]){
	int temp[length];
	MyMergeSort(arr, temp, 0, length - 1);
}

int main(int argc, char * argv[])
{
	int a[8] = {50, 10, 20, 30, 70, 40, 80, 60};
	MergeSort(8,a);
	for(int i=0; i<8; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}