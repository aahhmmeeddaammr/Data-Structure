#include <bits/stdc++.h>
using namespace std;
// Function to merge two sorted subarrays of arr
// The first subarray is arr[l..mid]
// The second subarray is arr[mid+1..r]
void merge(vector<int>& arr, int l, int r) {
    int mid = (r + l) / 2;
    int LeftSize = mid - l + 1;
    int RightSize = r - mid;
    int RightIndex = 0, LeftIndex = 0, Index = l;

    // Temporary vectors to hold the left and right subarrays
    vector<int> Left, Right;

    // Copy data to temporary vectors Left and Right
    for (int i = 0; i < LeftSize; i++) {
        Left.push_back(arr[l + i]);
    }
    for (int i = 0; i < RightSize; i++) {
        Right.push_back(arr[mid + 1 + i]);
    }

    // Merge the temporary vectors back into arr[l..r]
    while (RightIndex < RightSize && LeftIndex < LeftSize) {
        if (Right[RightIndex] < Left[LeftIndex]) {
            arr[Index++] = Right[RightIndex++];
        } else {
            arr[Index++] = Left[LeftIndex++];
        }
    }

    // Copy the remaining elements of Left, if any
    while (LeftIndex < LeftSize) {
        arr[Index++] = Left[LeftIndex++];
    }

    // Copy the remaining elements of Right, if any
    while (RightIndex < RightSize) {
        arr[Index++] = Right[RightIndex++];
    }
}

// Function to perform merge sort on arr[l..r]
void Merge_Sort(vector<int>& arr, int l, int r) {
    if (l < r) {
        // Find the midpoint
        int mid = (l + r) / 2;

        // Recursively sort the first half
        Merge_Sort(arr, l, mid);

        // Recursively sort the second half
        Merge_Sort(arr, mid + 1, r);

        // Merge the two sorted halves
        merge(arr, l, r);
    }
}
int main() {
    vector arr={10,30,0,-1,11,5,4};
    Merge_Sort(arr,0,6);
    for (auto i :arr) {
        cout<<i<<"  ";
    }
}