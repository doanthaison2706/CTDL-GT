#include <iostream>

using namespace std;

class MaxHeap {
private:
    int* heap;          
    int capacity;        
    int size;            
    // Hàm để duy trì tính chất heap 
    void heapifyUp(int index) {
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    // Hàm để duy trì tính chất heap 
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
    // Hàm khởi tạo 
    MaxHeap(int cap) {
        capacity = cap;
        heap = new int[capacity];
        size = 0;
    }
    // Thêm phần tử vào heap
    void push(int value) {
        if (size == capacity) {
            throw overflow_error("Heap is full");
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }
    // loại bỏ phần tử
    int pop() {
        if (size == 0) {
            throw underflow_error("Heap is empty");
        }
        int rootValue = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return rootValue;
    }
    // Lấy phần tử trên cùng
    int top() {
        if (size == 0) {
            throw underflow_error("Heap is empty");
        }
        return heap[0];
    }
    // Kiểm tra cây heap có rỗng không
    bool empty() {
        return size == 0;
    }
    // In cây heap 
    void print() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    // Hàm hủy 
    ~MaxHeap() {
        delete[] heap;
    }
};

int main() {
    int n;
    cout << "Nhập số lượng phần tử trong heap: ";
    cin >> n;
    MaxHeap heap(n);
    cout << "Nhập các phần tử của heap: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        heap.push(value);
    }
    cout << "Cây heap ban đầu: ";
    heap.print();
    cout << "Dãy số giảm dần: ";
    while (!heap.empty()) {
        cout << heap.pop() << " "; 
    }
    cout << endl;
    return 0;
}
