#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {

    bool swapped = false;

    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped){
            break;
        }
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

    bubbleSort(arr, size);
    validate(arr, size);
    print(arr, size);

    return 0;
}
