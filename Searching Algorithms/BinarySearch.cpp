#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int arr[], int n, int el){

    sort(arr, arr + n);

    int idx = -1;
    int start = 0;
    int end = n - 1;

    while (start <= end){

        int mid = start + (end - start) / 2;

        if (arr[mid] == el){
            return mid;

        } else if (arr[mid] < el) {
            start = mid + 1;

        } else {
            end = mid - 1;
        }
    }

    return idx;
}

void print(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main(){

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size] = {};

    for(int i = 0; i < size; i++){
        cout << "Enter the value of element" << i + 1 << " : ";
        cin >> arr[i];
    }

    int toFind;
    cout << "Enter the element you want to search: ";
    cin >> toFind;

    int result;
    result = binarySearch(arr, size, toFind);

    if (result == -1){
        cout << toFind << " not found in ";
        print(arr, size);
    } else {
        cout << toFind << " found at index " << result << endl;
    }

    return 0;
}
