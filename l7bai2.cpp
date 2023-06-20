#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm ð? hi?n th? heap
void displayHeap(vector<int>& heap) {
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

// Hàm ð? hoán ð?i hai ph?n t?
void swapElements(vector<int>& heap, int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// Hàm ð? ki?m tra và ch?nh l?i heap khi m?t ph?n t? m?i ðý?c thêm vào
void heapifyUp(vector<int>& heap, int index) {
    int parent = (index - 1) / 2;

    if (index > 0 && heap[index] > heap[parent]) {
        swapElements(heap, index, parent);
        heapifyUp(heap, parent);
    }
}

// Hàm ð? ki?m tra và ch?nh l?i heap khi m?t ph?n t? b? xóa
void heapifyDown(vector<int>& heap, int index, int heapSize) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < heapSize && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }

    if (rightChild < heapSize && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swapElements(heap, index, largest);
        heapifyDown(heap, largest, heapSize);
    }
}

// Hàm ð? chèn m?t ph?n t? m?i vào heap
void insertElement(vector<int>& heap, int value) {
    heap.push_back(value);
    heapifyUp(heap, heap.size() - 1);
}

// Hàm ð? xóa m?t ph?n t? kh?i heap
void deleteElement(vector<int>& heap, int value) {
    int index = -1;
    for (int i = 0; i < heap.size(); i++) {
        if (heap[i] == value) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Ph?n t? không t?n t?i trong heap." << endl;
        return;
    }

    swapElements(heap, index, heap.size() - 1);
    heap.pop_back();

    heapifyDown(heap, index, heap.size());
    heapifyUp(heap, index);
}

// Hàm ð? s?p x?p heap theo th? t? gi?m d?n
void heapSort(vector<int>& heap) {
    int heapSize = heap.size();

    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        heapifyDown(heap, i, heapSize);
    }

    for (int i = heapSize - 1; i >= 1; i--) {
        swapElements(heap, 0, i);
        heapifyDown(heap, 0, i);
    }
}

int main() {
    vector<int> heap = {45, 36, 54, 27, 63, 72, 61, 18};

    cout << "Heap ban ð?u: ";
    displayHeap(heap);

    int newValue = 80;
    insertElement(heap, newValue);
    cout << "Heap sau khi chèn ph?n t? " << newValue << ": ";
    displayHeap(heap);

    int deleteValue = 54;
    deleteElement(heap, deleteValue);
    cout << "Heap sau khi xóa ph?n t? " << deleteValue << ": ";
    displayHeap(heap);

    heapSort(heap);
    cout << "S?p x?p heap theo th? t? gi?m d?n: ";
    displayHeap(heap);

    return 0;
}

