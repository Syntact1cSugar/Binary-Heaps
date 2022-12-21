#include<iostream>
void swap(int* A,int i,int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
	return;
}
int parent(int i)
{
	return (i-1)/2;
}
int left(int i)
{
	return 2 * i +1;
}
int right(int i)
{
	return 2 * i + 2;
}

void MaxHeapify(int* A,int heapSize,int i)
{
	int l = left(i),r = right(i);
	int largest = i;
	if(l < heapSize && A[l] > A[i])
		largest = l;
	if(r < heapSize && A[r] > A[l])
		largest = r;
	if(largest != i)
	{
		//Swap i and largest
		swap(A,i,largest);
		MaxHeapify(A,heapSize,largest);
	}
	return;
}

void buildMaxHeap(int* A,int length,int heapSize)
{
	//Last parent = n-1-1/2
	//Leaf Nodes are n-1-1/2+1,n-1-1/2+2,n-1-1/2+3,.....,n-1
	for(int i=length-1-1/2;i>=0;i--)
		MaxHeapify(A,heapSize,i);
	return;
}

void HeapSort(int* A,int length,int heapSize)
{
	buildMaxHeap(A,length,heapSize);

	for(int i=length-1;i>0;i--)
	{
		swap(A,0,i);
		heapSize--;
		MaxHeapify(A,heapSize,0);
	}
	return;
}

int main()
{
	int A[] = {4,1,3,2,16,9,10,14,8,7};
	int length = 10,heapSize = 10;
	HeapSort(A,length,heapSize);
	for(int i:A)
		std::cout << i << "\t";
	return 0;
}
