#include <iostream>

using namespace std;

int linearSearch(int arr[], int n, int el){

    int idx = -1;

    for (int i = 0; i < n; i++){
        if (arr[i] == el){
            idx = i;
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

    result = linearSearch(arr, size, toFind);

    if (result == -1){
        cout << toFind << " not found in ";
        print(arr, size);
    } else {
        cout << toFind << " found at index " << result << endl;
    }

    return 0;
}