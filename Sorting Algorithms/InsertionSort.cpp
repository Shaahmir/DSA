#include <iostream>
#include <algorithm>

using namespace std;

void insertionSort(int arr[], int n) {

    for (int i = 1; i < n; i++){

        int curr = arr[i];
        int prev = i - 1;

        while(prev >= 0 && arr[prev] > curr){
            arr[prev + 1] = arr[prev];
            prev--;
        }

        swap(arr[prev + 1], curr);
    }
}

void print(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

void validate(int arr[], int n){

    bool swapped = false;
    for(int i = 0; i < n - 1; i++){
        if (arr[i] > arr[i + 1]){
            swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }

    if(!swapped){
        cout << "The array is sorted correctly!" << endl;
        
    } else {
        cout << "The array is not sorted correctly!" << endl;
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

    insertionSort(arr, size);
    validate(arr, size);
    print(arr, size);

    return 0;
}
