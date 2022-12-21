#include<iostream>
#include<climits>

void swap(int* A,int i,int j)
{
	if(!A)return;
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
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
int MAX_HEAPIFY(int* A,int i,int heapSize)
{
	if(!A)return 0;
	int l = left(i),r = right(i),largest = i;
	if(l < heapSize && A[l] > A[i])
		largest = l;
	if(r < heapSize && A[r] > A[largest])
		largest = r;
	if(largest != i)
	{
		swap(A,i,largest);
		MAX_HEAPIFY(A,largest,heapSize);
	}
	return 1;
}

int HEAP_MAXIMUM(int* A)
{
	return A[0];
}

int EXTRACT_MAX(int* A,int* heapSize)
{
	if(!A)return 0;
	int max = A[0];
	A[0] = A[*(heapSize)-1];
	*heapSize = *heapSize - 1;
	MAX_HEAPIFY(A,0,*heapSize);
	return max;
}
int INCREASE_KEY(int* A,int i,int k,int heapSize)//k = new key value
{
	if(heapSize < 1)return 0;
	A[i]  = k;//altered the value of ith key 
	while(i > 0 && A[parent(i)] < A[i])
	{
		swap(A,parent(i),i);
		i = parent(i);
	}
	return 1;
}
int INSERT_KEY(int *A,int x,int* heapSize)
{
	*heapSize = *heapSize  + 1;
	A[(*heapSize)-1] = INT_MIN;
	INCREASE_KEY(A,*heapSize-1,x,*heapSize);
	return 1;
}


int main()
{
	int* A = new int[100];
	int heapSize = 0;
	INSERT_KEY(A,21,&heapSize);
	INSERT_KEY(A,10,&heapSize);
	INSERT_KEY(A,-2,&heapSize);
	INSERT_KEY(A,-100,&heapSize);
	INSERT_KEY(A,1,&heapSize);
	INSERT_KEY(A,34,&heapSize);
	std::cout << EXTRACT_MAX(A,&heapSize) << std::endl;//34
	std::cout << EXTRACT_MAX(A,&heapSize) << std::endl;
	std::cout << heapSize << std::endl;
	delete[] A;
	return 0;
}
