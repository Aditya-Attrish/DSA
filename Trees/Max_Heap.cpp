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
	void PercolateDown(int i = 0) {
		int max = i,
		temp;
		int left = i*2+1;
		int right = i*2+2;
		if(left < size && array[i] < array[left])
			max = left;
		if(right < size && array[max] < array[right])
			max = right;
		if(max != i) {
			temp = array[i];
			array[i] = array[max];
			array[max] = temp;
			PercolateDown(max);
		}

	}
	int* Resize() {

		int *arr, *array_old = array;
		capacity = capacity * 2;
		arr = new int[capacity];
		for(short i = 0; i < size; i++)
			arr[i] = array_old[i];
		delete []array_old;
		return arr;
	}
	public:
	Heap(int capacity = 2) {
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
		int i;
		if(size == capacity)
			array = Resize();
		i = size++;
		while(i >= 1 && data > array[(i-1)/2]) {
			array[i] = array[(i-1)/2];
			i = (i-1)/2;
		}
		array[i] = data;
	}
	bool Delete() {
		if(size == 0)
		return false;
		array[0] = array[size-1];
		size--;
		PercolateDown();
		return true;
	}
	void printAll() {
		for(int i = 0; i < size; i++)
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