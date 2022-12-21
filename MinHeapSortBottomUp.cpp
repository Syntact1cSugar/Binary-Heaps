#include<iostream>

class Heap
{
	public:
		int* H;
		int n,heapSize;
		Heap(int* A,int n)
		{
			this->n = n;
			this->heapSize = n;
			this->H = new int[n];
			for(int i=0;i<n;i++)
				this->H[i] = A[i];
		}
		//Utility Functions
		void swap(int,int);
		void print(void);
		//Core Functions
		void MIN_HEAPIFY(int);
		void BUILD_MIN_HEAP(void);
		void HEAP_SORT(void);
};
//Utility/Helper Functions Implementation
void Heap::swap(int i,int j)
{
	int temp = this->H[i];
	this->H[i] = this->H[j];
	this->H[j] = temp;
	return;
}
void Heap::print()
{
	for(int i=0;i<this->n;i++)
		std::cout << this->H[i] << "\t";
	return;
}
//Core Functions Implementation
void Heap::MIN_HEAPIFY(int i)
{
	int smallest = i;
	int left = (i<<1)+1;
	int right = (i<<1)+2;
	if(left < this->heapSize && this->H[left] < this->H[smallest])
		smallest = left; 
	if(right < this->heapSize && this->H[right] < this->H[smallest])
		smallest = right;
	if(smallest != i)
	{
		this->swap(i,smallest);
		this->MIN_HEAPIFY(smallest);
	}
	return;
}
void Heap::BUILD_MIN_HEAP()
{
	//Leaf Nodes are ((n-1)-1/2)+1,((n-1)-1/2)+2,..........,n-1
	//Leaf Nodes are the roots of trivial min heaps
	//Last Parent = ((n-1)-1)/2
	for(int i=((n-1)-1)/2;i>=0;i--)
		this->MIN_HEAPIFY(i);
	return;
}
void Heap::HEAP_SORT()
{
	this->BUILD_MIN_HEAP();
	for(int i=0;i<n-1;i++)
	{
		this->swap(0,heapSize-1);
		--(this->heapSize);
		this->MIN_HEAPIFY(0);
	}
	return;
}
int main()
{
	int A[] = {20,-2,34,100,-234,48,34,1,2,3,4,51,3,-3492};
	//Expected -3,-2,30,20,-1
	Heap* H = new Heap(A,*(&A+1)-A);
	H->HEAP_SORT();
	H->print();
	return 0;
}
