#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class MaxHeap {
private:
    T* heap;          
    int capacity;    
    int size;         
    // Hàm để duy trì tính chất heap (heapify từ dưới lên)
    void heapifyUp(int index) {
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    // Hàm để duy trì tính chất heap (heapify từ trên xuống)
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
        heap = new T[capacity];
        size = 0;
    }
    // Thêm phần tử vào heap
    void push(T value) {
        if (size == capacity) {
            throw overflow_error("Heap is full");
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }
    // Loại bỏ phần tử lớn nhất (gốc của heap)
    T pop() {
        if (size == 0) {
            throw underflow_error("Heap is empty");
        }
        T rootValue = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return rootValue;
    }
    // Lấy phần tử lớn nhất (gốc của heap) mà không loại bỏ
    T top() const {
        if (size == 0) {
            throw underflow_error("Heap is empty");
        }
        return heap[0];
    }
    // Kiểm tra cây heap có rỗng không
    bool empty() const {
        return size == 0;
    }
    // In cây heap
    void print() const {
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
    MaxHeap<int> heap(n);
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
    return 0;
}
