/*
 * Author      : Midhun P
 * Description : Max and min heap
 * Remarks     : Build max and min heaps from a input array of elements
 */

#include <iostream>

using namespace std;

void print_array(int *arr, int n) {
    for(int i = 0; i < n; ++i) 
        cout << arr[i] << ", ";
    cout << "\b\b " << endl;
}

void heapify(int *arr, int n, int is_max_heap, int i) {
    int root = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(is_max_heap) {
        if(left < n && arr[left] > arr[root])
            root = left;

        if(right < n && arr[right] > arr[root])
            root = right;
    } else {
        if(left < n && arr[left] < arr[root])
            root = left;

        if(right < n && arr[right] < arr[root])
            root = right;
    }

    if(root != i) {
        swap(arr[i], arr[root]);
        heapify(arr, n, is_max_heap, root);
    }
}

void build_heap(int *arr, int n, int is_max_heap) {
    for(int i = n/2 - 1; i >= 0; --i)
        heapify(arr, n, is_max_heap, i);
}

int main() {
    int n = 10;
    int arr[] = {15, 16, 8, 5, 6, 30, 25, 17, 45, 4};

    cout << "Before\t: ";
    print_array(arr, n);

    build_heap(arr, n, 1);

    cout << "Max heap: ";
    print_array(arr, n);

    build_heap(arr, n, 0);

    cout << "Min heap: ";
    print_array(arr, n);

    return 0;
}