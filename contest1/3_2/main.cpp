#include <iostream>
#include <algorithm>

int* GetArray(int n){
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    return arr;
}
int BinarySearch(const int* arr, int n){
    int left = 0, right = n - 1;
    while (left < right - 1){
        int mid = (left + right) / 2;
        if (arr[mid] < arr[mid + 1])
            left = mid;
        else
            right = mid;
    }
    if (arr[left] > arr[right])
        return left;
    return right;
}
int main() {
    int n;
    int* arr;
    std::cin >> n;
    arr = GetArray(n);
    std::cout << BinarySearch(arr, n);
    delete[] arr;
    return 0;
}