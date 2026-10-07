#include <iostream>

using namespace std;

void reverse(int arr[], int n) {

    for (int i = 0; i < n / 2; i++){
        swap(arr[i], arr[n - i - 1]);
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

    reverse(arr, size);
    print(arr, size);

    return 0;
}
