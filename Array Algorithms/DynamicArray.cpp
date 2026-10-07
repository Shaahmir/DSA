#include <iostream>

using namespace std;

void display(const int* arr, int size){

    if (size == 0) {
        cout << "Array is empty." << endl;
        return;
    }

    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

void resize(int* &arr, int &capacity, int size){

    int newCapacity = capacity * 2;
    int * newArr = new int[newCapacity];


    for (int i = 0; i < size; i++){
        newArr[i] = arr[i];
    }

    delete[] arr;

    arr = newArr;
    capacity = newCapacity;

    cout << "Array resized to new capacity: " << newCapacity << endl;
}

void insert(int* &arr, int &capacity, int &size, int value){

    if (((double)(size + 1) / capacity) >= 0.70) {
        cout << "Array consumed more than 70% capacity. Resizing..." << endl;
        resize(arr, capacity, size);
    }

    arr[size] = value;
    size++;
    cout << "Inserted " << value << " into array" << endl;

}

bool remove(int* arr, int &size, int value){

    int index = -1;

    for(int i = 0; i < size; i++){
        if (arr[i] == value){
            index = i;
            break;
        }
    }

    if (index == -1){
        cout << "Value " << value << " not found in array" << endl;
        return false;
    }

    for (int i = index; i < size - 1; i++){
        arr[i] = arr[i + 1];
    }

    cout << "Removed " << value << endl;

    size--;
    return true;
}

int main() {
    
    int capacity = 0;
    int size = 0;

    while(true){
        cout << "Enter initial capacity of the array: ";
        cin >> capacity;

        if (capacity > 0){
            break;
        } else {
            cout << "Capacity must be greater than 0. Please try again." << endl;
        }
    }

    int * arr = new int[capacity];
    int value;

    while (true){

        int choice;

        cout << "Enter (1-4) for the following operations: " << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cin >> choice;

        switch (choice) {
            
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(arr, capacity, size, value);
                break;

            case 2:
                cout << "Enter value to remove: ";
                cin >> value;
                remove(arr, size, value);
                break;

            case 3:
                display(arr, size);
                break;

            case 4:
                cout << "Exiting...";
                delete[] arr;
                arr = nullptr;
                return 0;

            default:
                cout << "Wrong Choice!";
        }
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}
