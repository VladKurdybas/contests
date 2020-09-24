#include <iostream>
#include <algorithm>

int* GetArray(int n){
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    return arr;
}
int* GetSuffixMax(int* arr, int n){
    int* arr_suffix = new int[n];
    arr_suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i){
        arr_suffix[i] = std::max(arr_suffix[i + 1], arr[i]);
    }
    return arr_suffix;

}
void GetIndex(const int* arr_a, const int* arr_b_s, const int* arr_b, int n){
    int max = 0, index = 0, buf_index;
    for(int i = 0; i < n; i++)
        if((arr_a[i] + arr_b_s[i]) > max){
            index = i;
            max = (arr_a[i] + arr_b_s[i]);
        }
    std::cout << index << " ";
    buf_index = index;
    while(arr_b[buf_index] != arr_b_s[index])
        ++buf_index;
    std::cout << buf_index;
}
int main() {
    int n;
    int* arr_a, *arr_b, *arr_suffix;
    std::cin >> n;
    arr_a = GetArray(n);
    arr_b = GetArray(n);
    arr_suffix = GetSuffixMax(arr_b, n);
    GetIndex(arr_a, arr_suffix, arr_b, n);
    delete[] arr_a;
    delete[] arr_b;
    delete[] arr_suffix;
    return 0;
}