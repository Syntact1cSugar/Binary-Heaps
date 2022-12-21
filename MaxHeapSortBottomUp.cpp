#include<iostream>

//Left Child = i*2 + 1
//Right Child = i*2 + 2;
//Parent = (i-1)/2
class Heap
{
	public:
		int* H;
		int n,heapSize;
		Heap(int* A,int n)
		{
			this->H = new int[n];
			for(int i=0;i<n;i++)
				this->H[i] = A[i];
			//Intially Heap size = n
			this->heapSize = n;
			this->n = n;
		}
		void MAX_HEAPIFY(int);
		void BUILD_MAX_HEAP(void);
		void HEAP_SORT(void);
		//Utililty Functions
		void swap(int,int);
		void print(void);
};
//Utility/Helper Functions
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
//Core Functions
void Heap::MAX_HEAPIFY(int i)
{
	int largest = i;
	int left = (i<<1)+1;
	int right = (i<<1)+2;
	if(left < this->heapSize && this->H[left] > this->H[i])
		largest = left;
	if(right < this->heapSize && this->H[right] > this->H[largest])
		largest = right;
	if(largest != i)
	{
		this->swap(i,largest);
		MAX_HEAPIFY(largest);
	}
	return;
}
void Heap::BUILD_MAX_HEAP()
{
	//Leaf Nodes are ((n-1)-1/2)+1,((n-1)-1/2)+2,((n-1)-1/2i)+3,..,n-1;
	//Leaf Nodes are considered to be the roots of trivial max heaps
	//Last Parent = (n-1)-1/2
	for(int i=((this->n-1)-1)/2;i>=0;i--)
		this->MAX_HEAPIFY(i);
	return;
}
void Heap::HEAP_SORT()
{
	this->BUILD_MAX_HEAP();
	for(int i=0;i<this->n-1;i++)
	{
		this->swap(0,this->heapSize-1);
		--(this->heapSize);
		this->MAX_HEAPIFY(0);
	}
	return;
}
int main()
{
	int A[] = {89,7,-1,34,98,19,34,13403,-234,8590,302,-2};
	Heap* h = new Heap(A,*(&A+1)-A);
	h->HEAP_SORT();
	h->print();
	delete h;
	return 0;
}
