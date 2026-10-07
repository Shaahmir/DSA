#include <iostream>
#include<climits>

using namespace std;

// Kadane's Algorithm

int maxSubArraySum(int arr[], int n){

    int currSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i ++){

        currSum += arr[i];
        maxSum = max(currSum, maxSum);

        if (currSum < 0){
            currSum = 0;
        }
    }
    
    return maxSum;
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

    int maxSum = maxSubArraySum(arr, size);
    cout << "Max Sum: " << maxSum;

    return 0;
}
