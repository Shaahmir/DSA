#include <iostream>
#include<climits>
#include <algorithm>

using namespace std;

void countSort(int arr[], int n) {

    int range = INT_MIN;

    for (int i = 0; i < n; i++){
        range = max(range, arr[i]);
    }

    int freqArr[100001] = {0};

    for (int i = 0; i < n; i++){
        freqArr[arr[i]]++;
    }

    int index = 0;

    for (int i = 0; i <= range; i++){
        while(freqArr[i] > 0){
            arr[index++] = i;
            freqArr[i]--;
        }
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

    countSort(arr, size);
    validate(arr, size);
    print(arr, size);

    return 0;
}
