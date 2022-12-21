#include<iostream>
#include<climits>
void swap(int* A,int i,int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
	return;
}

void MIN_HEAPIFY(int* A,int i,int heapSize)
{
	int l = 2*i+1,r = 2*i+2;
	int smallest = i;
	if(l < heapSize && A[l] < A[i])
		smallest = l;
	if(r < heapSize && A[r] < A[smallest])
		smallest = r;
	if(smallest != i)
	{
		swap(A,i,smallest);
		MIN_HEAPIFY(A,smallest,heapSize);
	}
	return;
}


int HEAP_MINIMUM(int* A)
{
	return A[0];
}
int HEAP_EXTRACT_MIN_KEY(int* A,int* heapSize)
{
	int min = A[0];
	A[0] = A[*heapSize-1];
	*heapSize = *heapSize - 1;
	MIN_HEAPIFY(A,0,*heapSize);
	return min;
}

int HEAP_DECREASE_KEY(int* A,int i,int k)
{
	if(k > A[i])
	{
		std::cout << "New key is greater than the current key" << std::endl;
		return 0;
	}
	A[i] = k;
	while(i > 0 && A[(i-1)/2] > A[i])//Min heap property violation
	{
		swap(A,i,(i-1)/2);
		i = (i-1)/2;
	}
	return 1;
}
int HEAP_INSERT(int* A,int x,int* heapSize)
{
	*heapSize = *heapSize + 1;
	A[*heapSize - 1] = INT_MAX;
	HEAP_DECREASE_KEY(A,*heapSize-1,x);
	return 1;
}

int main()
{
	int* A = new int[100],heapSize = 0;
	HEAP_INSERT(A,100,&heapSize);
	HEAP_INSERT(A,-23,&heapSize);
	HEAP_INSERT(A,78,&heapSize);
	HEAP_INSERT(A,-100,&heapSize);
	HEAP_INSERT(A,80,&heapSize);
	std::cout << "Element at top : " << HEAP_MINIMUM(A) << std::endl;
	for(int i=0;i<5;i++)
		std::cout << HEAP_EXTRACT_MIN_KEY(A,&heapSize) << "\t";
	delete[] A;
	return 0;
}
