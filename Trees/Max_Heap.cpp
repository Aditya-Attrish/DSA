/*Heap is a tree with some special
/*Heap is a tree with some special
properly*/
/*this every node is greater than
both children.*/
//Delete first node.
/*Min
Max*/
#include<iostream>
using namespace std;
class Heap
{
	int *array;
	unsigned int size;
	unsigned int capacity;
	//int heap_type;
	void PercolateDown(unsigned int i = 0) {
		unsigned int max = i,
		left = i*2+1,
		right = i*2+2;
		if(left < size && array[i] < array[left])
			max = left;
		if(right < size && array[max] < array[right])
			max = right;
		if(max != i) {
			int temp = array[i];
			array[i] = array[max];
			array[max] = temp;
			PercolateDown(max);
		}

	}
	int* Resize() {

		int *arr, *array_old = array;
		capacity = capacity * 2;
		arr = new int[capacity];
		for(unsigned int i = 0; i < size; i++)
			arr[i] = array_old[i];
		delete []array_old;
		return arr;
	}
	public:
	Heap(unsigned int capacity = 2) {
		if(capacity < 2) //Handle the error.
			capacity = 2;
		this->capacity = capacity;
		size = 0;
		array = new int[this->capacity];
	}
	~Heap() {
		delete []array;
	}
	void insert(int data) {
		unsigned int i;
		if(size == capacity)
			array = Resize();
		i = size++;
		while(i >= 1 && data > array[(i-1)/2]) {
			array[i] = array[(i-1)/2];
			i = (i-1)/2;
		}
		array[i] = data;
	}
	int Delete() {
		if(size == 0)
		return -1;
		int v = array[0];
		array[0] = array[size-1];
		size--;
		PercolateDown();
		return v;
	}
	void printAll() {
		for(unsigned int i = 0; i < size; i++)
			cout<<array[i]<<" ";
	}
};
// 20 11 15 10 8 12 21
int main() {
	int t, data;
	cin>>t;
	Heap h(t);
	while(t-->0) {
		cin>>data;
		h.insert(data);
	}
	h.printAll();
    h.Delete();
	cout<<endl;
    h.printAll();
    cout<<endl;
	return 0;
}