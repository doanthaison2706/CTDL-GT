#include <iostream>

using namespace std;

class MaxHeap {
private:
    int* heap;          
    int capacity;        
    int size;  
	// Tính chất heap cho phương thức push         
    void heapifyUp(int index) {
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
	// Tính chất heap cho phương thức pop
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
public:
	// Constructor
    MaxHeap(int cap) {
        capacity = cap;
        heap = new int[capacity];
        size = 0;
    }
	// Phương thức push
    void push(int value) {
        if (size == capacity) {
            cout << "Heap is full" << endl;
			return;
        }
        heap[size] = -value; 
        heapifyUp(size);
        size++;
    }
	// Phương thức pop
    int pop() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
			return -1;
        }
        int rootValue = -heap[0];  
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return rootValue;
    }
	// Phương thức top
    int top() {
        if (size == 0) {
            cout << "Heap is empty"<< endl;
			return -1;
		}
		return -heap[0];  
    }
	// Lấy size của heap
    int getSize() {
        return size;
    }
	// Destructor
    ~MaxHeap() {
        delete[] heap;
    }
};

int main() {
    int n;
    cin >> n;
    MaxHeap pq(n); 
    for (int i = 0; i < n; i++) {
        int length;
        cin >> length;
        pq.push(length);
    }
    int total_cost = 0;
    while (pq.getSize() > 1) {
        int first = pq.top();  
        pq.pop();
        int second = pq.top(); 
        pq.pop();
        int cost = first + second;  
        total_cost += cost;        
        pq.push(cost);             
    }
    cout << total_cost << endl;  
    return 0;
}