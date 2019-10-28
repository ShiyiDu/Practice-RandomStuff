#include <stdio.h>
#include <stdlib.h>

static void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex);
static void MyMergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex);
void MergeSort(int length, int arr[]);

static void adjustHeap(int param1,int j, int inNums[]);
void HeapSort(int nums, int inNums[]);

static void MyQuickSort(int *a, int left, int right);
static void QuickSort(int len, int arr[]);

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
//////////////////////////////////////////////////heapsort/////////////
static void adjustHeap(int param1, int j, int inNums[])
{
	int temp=inNums[param1];
	for (int k=param1*2+1;k<j;k=k*2+1)
	{
		//如果右边值大于左边值，指向右边
		if (k+1<j && inNums[k]< inNums[k+1])
		{
			k++;
		}
		//如果子节点大于父节点，将子节点值赋给父节点,并以新的子节点作为父节点（不用进行交换）
		if (inNums[k]>temp)
		{
			inNums[param1]=inNums[k];
			param1=k;
		}
		else
			break;
	}
		//put the value in the final position
	inNums[param1]=temp;
}
//堆排序主要算法
void HeapSort(int nums,int inNums[])
{
	//1.构建大顶堆
	for (int i=nums/2-1;i>=0;i--)
	{
				//put the value in the final position
		adjustHeap(i,nums,inNums);
	}
	//2.调整堆结构+交换堆顶元素与末尾元素
	for (int j=nums-1;j>0;j--)
	{
				//堆顶元素和末尾元素进行交换
		int temp=inNums[0];
		inNums[0]=inNums[j];
		inNums[j]=temp;
 
		adjustHeap(0,j,inNums);//重新对堆进行调整
	}
}

void QuickSort(int len, int arr[]){
	MyQuickSort(arr, 0, len - 1);
}

static void MyQuickSort(int *a, int left, int right)
{
	if(left >= right)
	{
		return ;
	}
	int i = left;
	int j = right;
	int key = a[left];
	 
	while(i < j)
	{
		while(i < j && key <= a[j])
		{
			j--;
		}
		 
		a[i] = a[j];
		 
		while(i < j && key >= a[i])
		{
			i++;
		}
		 
		a[j] = a[i];
	}
	 
	a[i] = key;
	MyQuickSort(a, left, i - 1);
	MyQuickSort(a, i + 1, right);
}